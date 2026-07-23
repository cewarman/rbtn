import numpy as np

CARDINAL="CARDINAL"
DIGIT="DIGIT"
NUM_TWO_LIANG="NUM_TWO_LIANG"
HYPHEN_IGNORE="HYPHEN_IGNORE"
HYPHEN_RANGE="HYPHEN_RANGE"
HYPHEN_NEGATIVE="HYPHEN_NEGATIVE"
HYPHEN_MINUS="HYPHEN_MINUS"
HYPHEN_YEAR="HYPHEN_YEAR"
HYPHEN_MONTH="HYPHEN_MONTH"
HYPHEN_DAY="HYPHEN_DAY"
HYPHEN_RATIO="HYPHEN_RATIO"
SLASH_PER="SLASH_PER"
SLASH_OR="SLASH_OR"
SLASH_FRACTION="SLASH_FRACTION"
SLASH_YEAR="SLASH_YEAR"
SLASH_MONTH="SLASH_MONTH"
SLASH_DAY="SLASH_DAY"
SLASH_IGNORE="SLASH_IGNORE"
COLON_RATIO="COLON_RATIO"
COLON_HOUR="COLON_HOUR"
COLON_MINUTE="COLON_MINUTE"
COLON_IGNORE="COLON_IGNORE"
COLON_CHAPTER="COLON_CHAPTER"
POINT_POINT="POINT_POINT"
POINT_IGNORE="POINT_IGNORE"
POINT_YEAR="POINT_YEAR"
POINT_MONTH="POINT_MONTH"
POINT_DAY="POINT_DAY"
TILDE_RANGE="TILDE_RANGE"
TILDE_IGNORE="TILDE_IGNORE"
PLUS_ADD="PLUS_ADD"#加
PLUS_POSITIVE="PLUS_POSITIVE"#正
PLUS_ADVANCE="PLUS_ADVANCE"#PLUS i.e. Iphone 13+
PLUS_ABOVE="PLUS_ABOVE"#以上
PLUS_IGNORE="PLUS_IGNORE"#U+2030
INTERNET_SITE="INTERNET_SITE"
EMAIL="EMAIL"
TWO_AS_TO="TWO_AS_TO"
CIRCUMFLEX_EXPONENTIATION='CIRCUMFLEX_EXPONENTIATION'
CIRCUMFLEX_IGNORE='CIRCUMFLEX_IGNORE'
NUMERALS=['0','1','2','3','4','5','6','7','8','9','０','１','２','３','４','５','６','７','８','９']
SLASHS=['/','∕','╱','／']
HYPHENS=['-','－','—','─','–']
PLUSES=['+','＋','﹢']
POINTS=['．','.','‧']
TILDES=['～','~']
COLONS=[':','：','︰','﹕']
NUMERICAL_TOKEN=['十','百','千','萬','億','兆']
CIRCUMFLEXS=['^']
def has_NUMERALS(line):
	for tok in line:
		if(NUMERALS.count(tok)>0):
			return True
	return False
def has_LIANG_do_not_have_ER(s):
	fliang=False
	fer=True
	for tok in s:
		if(tok=='兩'):
			fliang=True
		if(tok=='二'):
			fer=False
	return (fliang and fer)
def has_numerical_token(s):
	for tok in s:
		if(NUMERICAL_TOKEN.count(tok)>0):
			return True
	return False
def add_class(output_crf_format_data,class_range,class_name):
	if(class_range[1]-class_range[0]==0):
		output_crf_format_data[class_range[0]]="S-{}".format(class_name)
	else:
		output_crf_format_data[class_range[0]]="B-{}".format(class_name)
		for i in range(class_range[0]+1,class_range[1]):
			output_crf_format_data[i]="I-{}".format(class_name)
		output_crf_format_data[class_range[1]]="E-{}".format(class_name)
def get_numerals_region(rule):
	region=[]
	flag=0
	start_idx=0
	end_idx=0
	temp_nsw=rule[3]+"e"
	for i in range(len(temp_nsw)):
		if(NUMERALS.count(temp_nsw[i])==1 and flag==0):
			start_idx=i
			flag=1
		elif(NUMERALS.count(temp_nsw[i])==1 and flag==1):
			continue
		elif(NUMERALS.count(temp_nsw[i])==0 and flag==1):
			if(temp_nsw[i]==',' or temp_nsw[i]=='，'):
				if(NUMERALS.count(temp_nsw[i+1])==1):
					continue
			end_idx=i-1
			flag=0
			region.append([start_idx,end_idx])
	return region
def dtw(source,target):
	cost_matrix=np.ones(len(source),len(target))
	print(cost_matrix)
	exit()
def R1_trans(output_crf_format_data,rule,sidx,eidx):
	point_flag=False
	point_idx=sidx
	for j in range(0,eidx-sidx):
		if(rule[3][j]=='.'):
			point_flag=True
			point_idx=point_idx+j
			break
	if(point_flag):
		add_class(output_crf_format_data,(sidx,point_idx-1),CARDINAL)
		add_class(output_crf_format_data,(point_idx,point_idx),POINT_POINT)
		add_class(output_crf_format_data,(point_idx+1,eidx),DIGIT)
		#print(rule,point_idx)
		#print(output_crf_format_data)
	else:
		add_class(output_crf_format_data,(sidx,eidx),CARDINAL)
		#print(rule,point_idx)
		#print(output_crf_format_data)
def R2_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	#dtw(source,target)
	point_flag=False
	point_idx=sidx
	for j in range(0,eidx-sidx):
		if(rule[3][j]=='.' and len(region) > 1):
			point_flag=True
			point_idx=point_idx+j
			break
	if(point_flag):
		add_class(output_crf_format_data,(sidx+region[0][0],point_idx-1),CARDINAL)
		add_class(output_crf_format_data,(point_idx,point_idx),POINT_POINT)
		add_class(output_crf_format_data,(point_idx+1,sidx+region[1][1]),DIGIT)
		#print(rule,point_idx)
		#print(output_crf_format_data)
	else:
		add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
		#print(rule,point_idx)
		#print(output_crf_format_data)
def R3_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(rule[3])):
		if(PLUSES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),PLUS_ADD)
	#return
def R4_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
def R5_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	add_class(output_crf_format_data,(sidx+region[2][0],sidx+region[2][1]),DIGIT)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[3][0],sidx+region[3][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[1][1]+1,sidx+region[1][1]+1),TILDE_RANGE)
	if(SLASHS.count(rule[3][region[0][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),SLASH_YEAR)
	elif(POINTS.count(rule[3][region[0][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),POINT_YEAR)
	elif(HYPHENS.count(rule[3][region[0][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),HYPHEN_YEAR)
	if(SLASHS.count(rule[3][region[2][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[2][1]+1,sidx+region[2][1]+1),SLASH_YEAR)
	elif(POINTS.count(rule[3][region[2][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[2][1]+1,sidx+region[2][1]+1),POINT_YEAR)
	elif(HYPHENS.count(rule[3][region[2][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[2][1]+1,sidx+region[2][1]+1),HYPHEN_YEAR)
def R6_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	if(len(region)==2):
		add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
		add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
	elif(len(region)==3):
		if((region[1][0]-region[0][1])==2):
			add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
			add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),DIGIT)
			add_class(output_crf_format_data,(sidx+region[2][0],sidx+region[2][1]),CARDINAL)
		else:
			add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
			add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
			add_class(output_crf_format_data,(sidx+region[1][1]+1,sidx+region[1][1]+1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[2][0],sidx+region[2][1]),DIGIT)
	elif(len(region)==4):
		add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),POINT_POINT)
		add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),DIGIT)
		add_class(output_crf_format_data,(sidx+region[2][0],sidx+region[2][1]),CARDINAL)
		add_class(output_crf_format_data,(sidx+region[2][1]+1,sidx+region[2][1]+1),POINT_POINT)
		add_class(output_crf_format_data,(sidx+region[3][0],sidx+region[3][1]),DIGIT)
def R7_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[2][0],sidx+region[2][1]),DIGIT)
	if(POINTS.count(rule[3][region[0][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),POINT_DAY)
	elif(HYPHENS.count(rule[3][region[0][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),HYPHEN_DAY)
	elif(SLASHS.count(rule[3][region[0][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),SLASH_DAY)
	if(POINTS.count(rule[3][region[1][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[1][1]+1,sidx+region[1][1]+1),POINT_MONTH)
	elif(HYPHENS.count(rule[3][region[1][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[1][1]+1,sidx+region[1][1]+1),HYPHEN_MONTH)
	elif(SLASHS.count(rule[3][region[1][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[1][1]+1,sidx+region[1][1]+1),SLASH_MONTH)
def R8_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
		if(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
		if(SLASHS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),SLASH_DAY)
def R9_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	dao_idx=-1
	for i in range(len(region)):
		if(int(rule[3][region[i][0]:region[i][1]+1])>31):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
			if(i>0):
				dao_idx=region[i][0]-1
				while(NUMERALS.count(rule[3][dao_idx])==0):
					if(TILDES.count(rule[3][dao_idx])>0):
						add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),TILDE_RANGE)
						break
					elif(HYPHENS.count(rule[3][dao_idx])>0):
						add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),HYPHEN_RANGE)
						break
					dao_idx=dao_idx-1
			if(SLASHS.count(rule[3][region[i][1]+1])>0):
				add_class(output_crf_format_data,(sidx+region[i][1]+1,sidx+region[i][1]+1),SLASH_YEAR)
			elif(HYPHENS.count(rule[3][region[i][1]+1])>0):
				add_class(output_crf_format_data,(sidx+region[i][1]+1,sidx+region[i][1]+1),HYPHEN_YEAR)
			elif(POINTS.count(rule[3][region[i][1]+1])>0):
				add_class(output_crf_format_data,(sidx+region[i][1]+1,sidx+region[i][1]+1),POINT_YEAR)
			if(SLASHS.count(rule[3][region[i+1][1]+1])>0):
				add_class(output_crf_format_data,(sidx+region[i+1][1]+1,sidx+region[i+1][1]+1),SLASH_MONTH)
			elif(HYPHENS.count(rule[3][region[i+1][1]+1])>0):
				add_class(output_crf_format_data,(sidx+region[i+1][1]+1,sidx+region[i+1][1]+1),HYPHEN_MONTH)
			elif(POINTS.count(rule[3][region[i+1][1]+1])>0):
				add_class(output_crf_format_data,(sidx+region[i+1][1]+1,sidx+region[i+1][1]+1),POINT_MONTH)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
def R10_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),DIGIT)
	if(POINTS.count(rule[3][region[0][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),POINT_MONTH)
	elif(HYPHENS.count(rule[3][region[0][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),HYPHEN_MONTH)
	elif(SLASHS.count(rule[3][region[0][1]+1])>0):
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),SLASH_MONTH)
	
def R11_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	slash_idx=region[1][0]-1
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
	while(NUMERALS.count(rule[3][slash_idx])==0):
		if(SLASHS.count(rule[3][slash_idx])>0):
			add_class(output_crf_format_data,(sidx+slash_idx,sidx+slash_idx),SLASH_FRACTION)
			break
		slash_idx=slash_idx-1
def R12_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	add_class(output_crf_format_data,(sidx+region[1][0]-1,sidx+region[1][0]-1),SLASH_YEAR)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
	if(len(region)>2):
		add_class(output_crf_format_data,(sidx+region[2][0]-1,sidx+region[2][0]-1),HYPHEN_RANGE)
		add_class(output_crf_format_data,(sidx+region[2][0],sidx+region[2][1]),CARDINAL)
def R12_subspecies_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	add_class(output_crf_format_data,(sidx+region[1][0]-1,sidx+region[1][0]-1),SLASH_IGNORE)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),DIGIT)
def R13_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),POINT_IGNORE)
def R14_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_IGNORE)
	#return
def R15_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	return
def R16_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
	colon_idx=region[1][0]-1
	while(NUMERALS.count(rule[3][colon_idx])==0):
		if(COLONS.count(rule[3][colon_idx])>0):
			add_class(output_crf_format_data,(sidx+colon_idx,sidx+colon_idx),COLON_RATIO)
			break
		colon_idx=colon_idx-1
def R17_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	#return
def R18_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	return
def R19_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])==0):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		dao_idx=region[i][0]-1
		while(NUMERALS.count(rule[3][dao_idx])==0):
			if(TILDES.count(rule[3][dao_idx])>0):
				add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),TILDE_RANGE)
				break
			elif(HYPHENS.count(rule[3][dao_idx])>0):
				add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),HYPHEN_RANGE)
				break
			dao_idx=dao_idx-1
def R20_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx,eidx),TILDE_RANGE)
def R21_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
		if(i%2==0):
			add_class(output_crf_format_data,(sidx+region[i][1]+1,sidx+region[i][1]+1),SLASH_MONTH)
def R22_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	hyphen_flag=False
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
			hyphen_flag=True
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	if(len(region)==2):
		if(hyphen_flag==False):
			add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
	elif(len(region)==3):
		if(POINTS.count(rule[region[0][1]+1])>0):
			add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),DIGIT)
			add_class(output_crf_format_data,(sidx+region[2][0],sidx+region[2][1]),CARDINAL)
		else:
			add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
			add_class(output_crf_format_data,(sidx+region[1][1]+1,sidx+region[1][1]+1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[2][0],sidx+region[2][1]),DIGIT)
	elif(len(region)==4):
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),POINT_POINT)
		add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),DIGIT)
		add_class(output_crf_format_data,(sidx+region[2][0],sidx+region[2][1]),CARDINAL)
		add_class(output_crf_format_data,(sidx+region[2][1]+1,sidx+region[2][1]+1),POINT_POINT)
		add_class(output_crf_format_data,(sidx+region[3][0],sidx+region[3][1]),DIGIT)
	
def R23_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	return
def R24_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	if(has_numerical_token(rule[6])==False and region[0][1]-region[0][0]>0 and not (region[0][1]-region[0][0]==1 and rule[3][region[0][0]]=='0')):
		add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	else:
		add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R25_trans(output_crf_format_data,rule,sidx,eidx,region):#need to be carefule i.e. 413，300美元
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R26_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])==0):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		dao_idx=region[i][0]-1
		while(NUMERALS.count(rule[3][dao_idx])==0):
			if(TILDES.count(rule[3][dao_idx])>0):
				add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),TILDE_RANGE)
				break
			elif(HYPHENS.count(rule[3][dao_idx])>0):
				add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),HYPHEN_RANGE)
				break
			dao_idx=dao_idx-1
def R27_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
		elif(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
		elif(COLONS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),COLON_CHAPTER)
		
	return
def R28_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(SLASHS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),SLASH_PER)
def R29_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R30_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R31_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(i>0):
			if(POINTS.count(rule[3][region[i][0]-1])>0 and NUMERALS.count(rule[3][region[i][0]-2])>0):
				add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
				add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
				continue
		if(has_numerical_token(rule[6])==False and region[i][1]-region[i][0]>0):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
			continue
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
def R32_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(i>0):
			dao_idx=region[i][0]-1
			while(NUMERALS.count(rule[3][dao_idx])==0):
				if(HYPHENS.count(rule[3][dao_idx])>0):
					add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),HYPHEN_RANGE)
				elif(TILDES.count(rule[3][dao_idx])>0):
					add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),TILDE_RANGE)
				dao_idx=dao_idx-1
		if(i>0):
			if(POINTS.count(rule[3][region[i][0]-1])>0 and NUMERALS.count(rule[3][region[i][0]-2])>0):
				add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
				add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
				continue
		if(has_numerical_token(rule[6])==False and region[i][1]-region[i][0]>0):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
			continue
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
def R33_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx,eidx),INTERNET_SITE)
def R34_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(i>0):
			if(POINTS.count(rule[3][region[i][0]-1])>0 and NUMERALS.count(rule[3][region[i][0]-2])>0):
				add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
				add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
				continue
		if(has_numerical_token(rule[6])==False and region[i][1]-region[i][0]>0):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
			continue
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
def R35_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		if(i>0):
			if(HYPHENS.count(rule[3][region[i][0]-1])):
				add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),HYPHEN_IGNORE)
def R36_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(rule[3][region[i][1]+1]=='年'):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
def R37_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
def R38_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx,eidx),EMAIL)
def R39_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
def R40_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[1][0]-1,sidx+region[1][0]-1),SLASH_MONTH)
	add_class(output_crf_format_data,(sidx+region[3][0]-1,sidx+region[3][0]-1),SLASH_MONTH)
	dao_idx=region[2][0]-1
	while(NUMERALS.count(rule[3][dao_idx])==0):
		if(TILDES.count(rule[3][dao_idx])>0):
			add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),TILDE_RANGE)
		elif(HYPHENS.count(rule[3][dao_idx])>0):
			add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),HYPHEN_RANGE)
		dao_idx=dao_idx-1
def R41_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
		if(SLASHS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),SLASH_MONTH)
def R42_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
		if(SLASHS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),SLASH_MONTH)
	dao_idx=region[2][0]-1
	while(NUMERALS.count(rule[3][dao_idx])==0):
		if(TILDES.count(rule[3][dao_idx])>0):
			add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),TILDE_RANGE)
		elif(HYPHENS.count(rule[3][dao_idx])>0):
			add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),HYPHEN_RANGE)
		dao_idx=dao_idx-1
def R43_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
		if(COLONS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),COLON_HOUR)
	dao_idx=region[2][0]-1
	while(NUMERALS.count(rule[3][dao_idx])==0):
		if(TILDES.count(rule[3][dao_idx])>0):
			add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),TILDE_RANGE)
		elif(HYPHENS.count(rule[3][dao_idx])>0):
			add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),HYPHEN_RANGE)
		dao_idx=dao_idx-1
def R44_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),POINT_POINT)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
def R45_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(rule[3])):
		if(PLUSES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),PLUS_ADD)
		elif(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_MINUS)
		elif(SLASHS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),SLASH_OR)
def R46_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0 and NUMERALS.count(rule[3][region[i][0]-2])>0):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
def R47_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R48_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),TWO_AS_TO)
def R49_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0 and NUMERALS.count(rule[3][region[i][0]-2])>0):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	ratio_idx=region[len(region)-1][0]-1
	while(COLONS.count(rule[3][ratio_idx])==0):
		ratio_idx=ratio_idx-1
	add_class(output_crf_format_data,(sidx+ratio_idx,sidx+ratio_idx),COLON_RATIO)
def R50_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0 and NUMERALS.count(rule[3][region[i][0]-2])>0):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
def R51_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(SLASHS.count(rule[3][region[i][0]-1])>0 and NUMERALS.count(rule[3][region[i][0]-2])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),SLASH_FRACTION)
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
def R52_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
def R53_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[1][0]-1,sidx+region[1][0]-1),COLON_HOUR)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
def R54_trans(output_crf_format_data,rule,sidx,eidx,region):#need to be carful i.e. November 18, 2022 Recent 
	#print(rule,region)
	if(has_numerical_token(rule[6])==False and region[0][1]-region[0][0]>0):
		add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	else:
		add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R55_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R56_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R57_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0]-1,sidx+region[0][0]-1),PLUS_ADD)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	#return
def R58_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0]-1,sidx+region[0][0]-1),POINT_POINT)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
def R59_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R60_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),SLASH_OR)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
def R61_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0 and NUMERALS.count(rule[3][region[i][0]-2])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(PLUSES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),PLUS_ADD)
		elif(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_MINUS)
		elif(SLASHS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),SLASH_FRACTION)
def R62_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	return
def R63_trans(output_crf_format_data,rule,sidx,eidx,region):#need to be careful A++
	#print(rule,region)
	for i in range(len(rule[3])):
		if(PLUSES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),PLUS_ADVANCE)
def R64_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),DIGIT)
	for i in range(len(rule[3])):
		if(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
		elif(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
def R65_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(rule[3])):
		if(PLUSES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),PLUS_ADD)
		elif(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_MINUS)
		elif(SLASHS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),SLASH_FRACTION)
def R66_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
	for i in range(len(rule[3])):
		if(POINTS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),POINT_POINT)
def R67_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
def R68_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	return
def R69_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[1][0]-1,sidx+region[1][0]-1),HYPHEN_IGNORE)
def R70_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	return
def R71_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[1][0]-1,sidx+region[1][0]-1),SLASH_MONTH)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
def R72_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(i>0):
			if(POINTS.count(rule[3][region[i][0]-1])>0 and NUMERALS.count(rule[3][region[i][0]-2])>0):
				add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
				add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
				continue
		if(has_numerical_token(rule[6])==False and region[i][1]-region[i][0]>0):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
			continue
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
		if(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
def R73_trans(output_crf_format_data,rule,sidx,eidx,region):#need to be careful
	#print(rule,region)
	for i in range(len(region)):
		if(has_numerical_token(rule[6])==True):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
def R74_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
def R75_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0]-1,sidx+region[0][0]-1),HYPHEN_IGNORE)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
def R76_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
	for i in range(len(rule[3])):
		if(POINTS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),POINT_POINT)
def R77_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	if(has_numerical_token(rule[6])==False and region[0][1]-region[0][0]>0):
		add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	else:
		add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R78_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	return
def R79_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	if(HYPHENS.count(rule[3][region[0][0]-1])>0):
		add_class(output_crf_format_data,(sidx+region[0][0]-1,sidx+region[0][0]-1),HYPHEN_NEGATIVE)
	if(PLUSES.count(rule[3][region[0][0]-1])>0):
		add_class(output_crf_format_data,(sidx+region[0][0]-1,sidx+region[0][0]-1),PLUS_POSITIVE)
	dao_idx=region[0][1]+1
	while(dao_idx<len(rule[3])):
		if(HYPHENS.count(rule[3][dao_idx])>0):
			add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),HYPHEN_RANGE)
		elif(TILDES.count(rule[3][dao_idx])>0):
			add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),TILDE_RANGE)
		dao_idx=dao_idx+1
def R80_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),HYPHEN_IGNORE)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),DIGIT)
def R81_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	if(len(region)>1):
		add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),POINT_POINT)
		add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),DIGIT)
	for i in range(len(rule[3])):
		if(PLUSES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),PLUS_ADVANCE)
def R82_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),HYPHEN_IGNORE)
	add_class(output_crf_format_data,(sidx+region[1][0],sidx+region[1][1]),CARDINAL)
def R83_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(SLASHS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),SLASH_PER)
		elif(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
		elif(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
def R84_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
		elif(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
def R85_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(PLUSES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),PLUS_ABOVE)
def R86_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(SLASHS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),SLASH_MONTH)
		elif(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
		elif(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
def R87_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(region[i][1]-region[i][0]<2):
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
	add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),SLASH_MONTH)
	add_class(output_crf_format_data,(sidx+region[len(region)-1][0]-1,sidx+region[len(region)-1][0]-1),SLASH_YEAR)
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
		elif(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
def R88_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(PLUSES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),PLUS_ADD)
def R89_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(rule[3])):
		if(PLUSES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),PLUS_ADD)
def R90_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(rule[3])):
		if(PLUSES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),PLUS_ADVANCE)
		elif(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_IGNORE)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R91_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
def R92_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
		elif(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
def R93_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	for i in range(1,len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
	for i in range(len(rule[3])):
		if(POINTS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),POINT_POINT)
def R94_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	add_class(output_crf_format_data,(sidx+region[0][1]+1,sidx+region[0][1]+1),COLON_HOUR)
	add_class(output_crf_format_data,(sidx+region[1][1]+1,sidx+region[1][1]+1),COLON_MINUTE)
def R95_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	if(HYPHENS.count(rule[3][region[0][0]-1])>0):
		add_class(output_crf_format_data,(sidx+region[0][0]-1,sidx+region[0][0]-1),HYPHEN_NEGATIVE)
	if(PLUSES.count(rule[3][region[0][0]-1])>0):
		add_class(output_crf_format_data,(sidx+region[0][0]-1,sidx+region[0][0]-1),PLUS_POSITIVE)
	dao_idx=region[0][1]+1
	while(dao_idx<len(rule[3])):
		if(HYPHENS.count(rule[3][dao_idx])>0):
			add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),HYPHEN_RANGE)
		elif(TILDES.count(rule[3][dao_idx])>0):
			add_class(output_crf_format_data,(sidx+dao_idx,sidx+dao_idx),TILDE_RANGE)
		dao_idx=dao_idx+1
def R96_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	if(has_numerical_token(rule[6])==False and region[0][1]-region[0][0]>0):
		add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
	else:
		add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R97_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
def R98_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
	for i in range(len(rule[3])):
		if(POINTS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),POINT_POINT)
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
	for i in range(len(rule[3])):
		if(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
def R99_trans(output_crf_format_data,rule,sidx,eidx,region):
	#print(rule,region)
	add_class(output_crf_format_data,(sidx+1,sidx+1),PLUS_IGNORE)
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),DIGIT)
def R100_trans(output_crf_format_data,rule,sidx,eidx,region):
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
	for i in range(len(rule[3])):
		if(SLASHS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),SLASH_IGNORE)
	#return
def R101_trans(output_crf_format_data,rule,sidx,eidx,region):
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	#return
def R102_trans(output_crf_format_data,rule,sidx,eidx,region):
	add_class(output_crf_format_data,(sidx+region[0][0],sidx+region[0][1]),CARDINAL)
	#return
def R103_trans(output_crf_format_data,rule,sidx,eidx,region):
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	idx=0
	plus_num=0
	while(idx<len(rule[3])):
		if(PLUSES.count(rule[3][idx])>0):
			if(plus_num==0):
				add_class(output_crf_format_data,(sidx+idx,sidx+idx),PLUS_POSITIVE)
			elif(plus_num==1):
				add_class(output_crf_format_data,(sidx+idx,sidx+idx),PLUS_ADD)
			plus_num=plus_num+1
		idx=idx+1
	#return
def R104_trans(output_crf_format_data,rule,sidx,eidx,region):
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
	#return
def R105_trans(output_crf_format_data,rule,sidx,eidx,region):
	return
def R106_trans(output_crf_format_data,rule,sidx,eidx,region):
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)

	for i in range(len(rule[3])):
		if(COLONS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),COLON_MINUTE)
		if(PLUSES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),PLUS_ABOVE)
	#return
def R107_trans(output_crf_format_data,rule,sidx,eidx,region):
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
			if(HYPHENS.count(rule[3][region[i][0]-1])>0):
				add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),HYPHEN_NEGATIVE)
	for i in range(len(rule[3])):
		if(CIRCUMFLEXS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),CIRCUMFLEX_EXPONENTIATION)
	#return
def R108_trans(output_crf_format_data,rule,sidx,eidx,region):
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RATIO)
	#return
def R109_trans(output_crf_format_data,rule,sidx,eidx,region):
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
	for i in range(len(rule[3])):
		if(POINTS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),POINT_POINT)
	#return
def R110_trans(output_crf_format_data,rule,sidx,eidx,region):
	for i in range(len(region)):
		add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
	for i in range(len(rule[3])):
		if(HYPHENS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),HYPHEN_RANGE)
		if(TILDES.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),TILDE_RANGE)
	#return
def R111_trans(output_crf_format_data,rule,sidx,eidx,region):
	for i in range(len(region)):
		if(POINTS.count(rule[3][region[i][0]-1])>0):
			add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),POINT_POINT)
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),DIGIT)
		else:
			add_class(output_crf_format_data,(sidx+region[i][0],sidx+region[i][1]),CARDINAL)
			if(HYPHENS.count(rule[3][region[i][0]-1])>0):
				add_class(output_crf_format_data,(sidx+region[i][0]-1,sidx+region[i][0]-1),HYPHEN_NEGATIVE)
	for i in range(len(rule[3])):
		if(CIRCUMFLEXS.count(rule[3][i])>0):
			add_class(output_crf_format_data,(sidx+i,sidx+i),CIRCUMFLEX_EXPONENTIATION)
	#return

def rules2crfoutput(output_crf_format_data,rules):
	for i in range(len(rules)):
		sidx=int(rules[i][1])
		eidx=int(rules[i][2])-1
		region=get_numerals_region(rules[i])
		#if(has_NUMERALS(rules[i][3])==False):
		#	continue
		if(rules[i][4]=='R1'):
			R1_trans(output_crf_format_data,rules[i],sidx,eidx)
		elif(rules[i][4]=='R2'):
			R2_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R3'):
			R3_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R4'):
			R4_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R5'):
			R5_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R6'):
			R6_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R7'):
			R7_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R8'):
			R8_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R9'):
			R9_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R10'):
			R10_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R11'):
			R11_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R12'):
			R12_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R12_subspecies'):
			R12_subspecies_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R13'):
			R13_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R14'):
			R14_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R15'):
			R15_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R16'):
			R16_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R17'):
			R17_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R18'):
			R18_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R19'):
			R19_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R20'):
			R20_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R21'):
			R21_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R22'):
			R22_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R23'):
			R23_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R24'):
			R24_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R25'):
			R25_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R26'):
			R26_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R27'):
			R27_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R28'):
			R28_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R29'):
			R29_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R30'):
			R30_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R31'):
			R31_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R32'):
			R32_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R33'):
			R33_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R34'):
			R34_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R35'):
			R35_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R36'):
			R36_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R37'):
			R37_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R38'):
			R38_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R39'):
			R39_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R40'):
			R40_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R41'):
			R41_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R42'):
			R42_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R43'):
			R43_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R44'):
			R44_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R45'):
			R45_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R46'):
			R46_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R47'):
			R47_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R48'):
			R48_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R49'):
			R49_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R50'):
			R50_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R51'):
			R51_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R52'):
			R52_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R53'):
			R53_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R54' or rules[i][4]=='unknow_R54'):
			R54_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R55'):
			R55_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R56'):
			R56_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R57'):
			R57_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R58'):
			R58_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R59'):
			R59_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R60'):
			R60_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R61'):
			R61_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R62'):
			R62_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R63'):
			R63_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R64'):
			R64_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R65'):
			R65_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R66'):
			R66_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R67'):
			R67_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R68'):
			R68_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R69' or rules[i][4]=='unknow_R69'):
			R69_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R70'):
			R70_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R71'):
			R71_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R72'):
			R72_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R73'):
			R73_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R74'):
			R74_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R75'):
			R75_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R76'):
			R76_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R77'):
			R77_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R78'):
			R78_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R79'):
			R79_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R80'):
			R80_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R81'):
			R81_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R82'):
			R82_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R83'):
			R83_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R84'):
			R84_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R85'):
			R85_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R86'):
			R86_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R87'):
			R87_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R88'):
			R88_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R89'):
			R89_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R90'):
			R90_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R91'):
			R91_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R92'):
			R92_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R93'):
			R93_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R94'):
			R94_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R95'):
			R95_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R96'):
			R96_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R97'):
			R97_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R98'):
			R98_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R99'):
			R99_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R100'):
			R100_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R101'):
			R101_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R102'):
			R102_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R103'):
			R103_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R104'):
			R104_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R105'):
			R105_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R106'):
			R106_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R107'):
			R107_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R108'):
			R108_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R109'):
			R109_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R110'):
			R110_trans(output_crf_format_data,rules[i],sidx,eidx,region)
		elif(rules[i][4]=='R111'):
			R111_trans(output_crf_format_data,rules[i],sidx,eidx,region)



import sys

if(len(sys.argv)!=2):
	print("Usage: python3 training_data_gen.py non_standard_word_mark > output.crf_format")
	sys.exit()

NSWMs=[]
with open(sys.argv[1],'r',encoding='utf8') as f:
	raw_nswms=[line.strip('\n') for line in f.readlines()]
	raw_nswms=raw_nswms[:len(raw_nswms)-1]
	row_idx=0
	while row_idx<len(raw_nswms):
		row=raw_nswms[row_idx]
		tab_idx=len(row)-1
		while row[tab_idx]!='\t':
			tab_idx=tab_idx-1
		row_nsw_num=int(row[tab_idx+1:])
		row=row[:tab_idx]
		if(row_nsw_num>0):
			temp_nswms=raw_nswms[row_idx+1:row_idx+row_nsw_num+1]
			for temp_idx in range(len(temp_nswms)):
				temp_nswms[temp_idx]=temp_nswms[temp_idx][1:]
			NSWMs.append([row,row_nsw_num,[line.split("∥\t") for line in temp_nswms]])
		row_idx=row_idx+row_nsw_num+1
		#print(row,'\t',row_nsw_num,NSWMs)

def patch2crfoutput(output_crf_format_data,rawline,rules):
	for i in range(len(rawline)):
		if(SLASHS.count(rawline[i])>0 and output_crf_format_data[i]=='O'):
			output_crf_format_data[i]='S-'+SLASH_IGNORE
		elif(POINTS.count(rawline[i])>0 and output_crf_format_data[i]=='O'):
			output_crf_format_data[i]='S-'+POINT_IGNORE
		elif(TILDES.count(rawline[i])>0 and output_crf_format_data[i]=='O'):
			output_crf_format_data[i]='S-'+TILDE_IGNORE
		elif(HYPHENS.count(rawline[i])>0 and output_crf_format_data[i]=='O'):
			output_crf_format_data[i]='S-'+HYPHEN_IGNORE
		elif(PLUSES.count(rawline[i])>0 and output_crf_format_data[i]=='O'):
			output_crf_format_data[i]='S-'+PLUS_ADD
		elif(COLONS.count(rawline[i])>0 and output_crf_format_data[i]=='O'):
			output_crf_format_data[i]='S-'+COLON_IGNORE
		elif(CIRCUMFLEXS.count(rawline[i])>0 and output_crf_format_data[i]=='O'):
			output_crf_format_data[i]='S-'+CIRCUMFLEX_IGNORE
	for i in range(len(rules)):
		sidx=int(rules[i][1])
		eidx=int(rules[i][2])-1
		region=get_numerals_region(rules[i])
		for j in range(len(region)):
			if(region[j][0]==region[j][1] and 
				(rules[i][3][region[j][0]]=='2' or rules[i][3][region[j][0]]=='２') and 
				has_LIANG_do_not_have_ER(rules[i][6])):
				output_crf_format_data[sidx+region[j][0]]='S-'+NUM_TWO_LIANG


for i in range(len(NSWMs)):
	output_crf_format_data=[]
	for j in range(len(NSWMs[i][0])):
		output_crf_format_data.append('O')
	rules2crfoutput(output_crf_format_data,NSWMs[i][2])
	patch2crfoutput(output_crf_format_data,NSWMs[i][0],NSWMs[i][2])
	if(True):
		for j in range(len(output_crf_format_data)):
			if(NSWMs[i][0][j]==' '):
				print("　\t{}".format(output_crf_format_data[j]))
			elif(NSWMs[i][0][j]=='\t'):
				print("\\t\t{}".format(output_crf_format_data[j]))
			else:
				print("{}\t{}".format(NSWMs[i][0][j],output_crf_format_data[j]))
		print()