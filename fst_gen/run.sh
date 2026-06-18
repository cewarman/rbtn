rm binary/*
rm temp/*
isym="./symlist/isyms.txt"
osym="./symlist/osyms.txt"
class2extended_class="./isym2class/class2extended_class.txt"
class2extended_class2="./isym2class/extend2.txt"
B_class2extended_class="./binary/class2extended_class.fst"
B_class2extended_class2="./binary/extend2.fst"
S_class2extended_class="./binary/S_class2extended_class.fst"
S_class2extended_class2="./binary/S_extend2.fst"
isym2class="./isym2class/isym2class.txt"
B_isym2class="./binary/binary_isym2class.fst"
S_isym2class="./binary/S_binary_isym2class.fst"
B_extend_class_temp="./binary/extended_class_temp.fst"
S_extend_class_temp="./binary/S_extended_class_temp.fst"
B_extend_class_temp2="./binary/extended_class_temp2.fst"
extend_class_temp="./temp/extended_class_temp.txt"
extend_class_temp2="./temp/extended_class_temp2.txt"
reorder_extend_class_temp2="./temp/reorder_extended_class_temp2.txt"
extend_class="./temp/extended_class.txt"
extend_class2="./temp/extended_class2.txt"
union_extend_class="./temp/union_extended_class.txt"
B_union_extend_class="./binary/union_extended_class.fst"
S_extend_class="./binary/S_extended_class.fst"
rule_list="rule_list.txt"
all_sym="./temp/all_sym.txt"
S_all_sym="./temp/S_all_sym.txt"
SQ_all_sym="./temp/SQ_all_sym.txt"
SQ_all_sym_WO="./temp/SQ_all_sym_WO.txt"
find "$(pwd)" | grep rules | grep txt > $rule_list
while read p; do
    awk '{ print $3 }' $p >> $all_sym
    awk '{ print $4 }' $p >> $all_sym
done <$rule_list
awk '{ print $3 }' $isym2class >> $all_sym
awk '{ print $4 }' $isym2class >> $all_sym
awk '{ print $3 }' $class2extended_class >> $all_sym
awk '{ print $4 }' $class2extended_class >> $all_sym
awk '{ print $3 }' $class2extended_class2 >> $all_sym
awk '{ print $4 }' $class2extended_class2 >> $all_sym
sed  '/^$/d' < $all_sym | sort > $S_all_sym
LC_ALL=C uniq < $S_all_sym > $SQ_all_sym
i=1
echo "<eps> 0" > $SQ_all_sym_WO
while read p; do
    if [ "$p" != "<eps>" ]
    then
        echo "$p $i" >> $SQ_all_sym_WO
        i=$((i+1))
    fi
done <$SQ_all_sym
cp $SQ_all_sym_WO $isym
cp $SQ_all_sym_WO $osym
fstcompile --isymbols=$isym --osymbols=$osym --keep_isymbols --keep_osymbols $isym2class $B_isym2class
fstcompile --isymbols=$isym --osymbols=$osym --keep_isymbols --keep_osymbols $class2extended_class $B_class2extended_class
fstcompile --isymbols=$isym --osymbols=$osym --keep_isymbols --keep_osymbols $class2extended_class2 $B_class2extended_class2
fstarcsort --sort_type=olabel $B_isym2class $S_isym2class
fstarcsort --sort_type=ilabel $B_class2extended_class $S_class2extended_class
fstcompose $S_isym2class $S_class2extended_class $B_extend_class_temp

fstarcsort --sort_type=olabel $B_extend_class_temp $S_extend_class_temp
fstarcsort --sort_type=ilabel $B_class2extended_class2 $S_class2extended_class2
fstcompose $S_extend_class_temp $S_class2extended_class2 $B_extend_class_temp2

fstprint --isymbols=$isym --osymbols=$osym $B_extend_class_temp $extend_class_temp
fstprint --isymbols=$isym --osymbols=$osym $B_extend_class_temp2 $extend_class_temp2
start_idx=$(awk 'END{print $1}' $extend_class_temp)
nlines=$(awk 'END{print NR}' $extend_class_temp2)
echo -n "" > $reorder_extend_class_temp2
for i in $(seq 1 $nlines); do
    istate=$(awk 'NR=='$i'{print $1}' $extend_class_temp2)
    ostate=$(awk 'NR=='$i'{print $2}' $extend_class_temp2)
    iitem=$(awk 'NR=='$i'{print $3}' $extend_class_temp2)
    oitem=$(awk 'NR=='$i'{print $4}' $extend_class_temp2)
    if [ $istate -gt 0 ];then
        istate=$(($istate+$start_idx))
    fi
    if [ $ostate -gt 0 ];then
        ostate=$(($ostate+$start_idx))
    fi
    echo $istate'\t'$ostate'\t'$iitem'\t'$oitem >> $reorder_extend_class_temp2

done
cat $reorder_extend_class_temp2 $extend_class_temp $isym2class > $extend_class
sed -e 'N ; s/^0\n//' $extend_class > $union_extend_class
#sed '$d' $extend_class > $union_extend_class
#sed -e 'N ; s/0\n//'
fstcompile --isymbols=$isym --osymbols=$osym --keep_isymbols --keep_osymbols $union_extend_class $B_union_extend_class
fstarcsort --sort_type=olabel $B_union_extend_class $S_extend_class
last=""
all="./binary/binary_R_all.fst"
Dall="./binary/D_binary_R_all.fst"
MDall="./binary/MD_binary_R_all.fst"
RMDall="./binary/RMD_binary_R_all.fst"
result="../CRR_Final.txt"
while read p; do
    temp=${p%.*}
    name=${temp##*/}
    binR="./binary/binary_$name.fst"
    SbinR="./binary/S_binary_$name.fst"
    CSbinR="./binary/CS_binary_$name.fst"
    #CSR="./temp/CS_$name.txt"
    fstcompile --isymbols=$isym --osymbols=$osym --keep_isymbols --keep_osymbols $p $binR
    fstarcsort --sort_type=ilabel $binR $SbinR
    fstcompose $S_extend_class $SbinR $CSbinR
    #fstprint --isymbols=$isym --osymbols=$osym $CSbinR $CSR
    if [ "$last" != "" ]
    then
        fstunion $CSbinR $last $all
        last="$all"
    else
        last="$CSbinR"
    fi
done <$rule_list
fstdeterminize $all $Dall
fstminimize --allow_nondet=true $Dall $MDall
fstrmepsilon $MDall $RMDall
fstprint --isymbols=$isym --osymbols=$osym $RMDall $result
