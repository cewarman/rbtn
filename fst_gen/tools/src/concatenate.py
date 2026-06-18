import sys

if(len(sys.argv)!=4):
	print('Usage: python3 concatenate.py input1_fst input2_fst output_fst')
	exit(1)

def add_transitions_back_to_zero(fst):
	for i in range(len(fst)):
		fst[i][0]=int(fst[i][0])
		if(len(fst[i])==1 and fst[i][0]!=0):
			fst.append([fst[i][0], 0, '<eps>', '<eps>'])
	return fst

def state_stringtoint(fst):
	for i in range(len(fst)):
		fst[i][0]=int(fst[i][0])
		if(len(fst[i])>1):
			fst[i][1]=int(fst[i][1])
	return fst

def get_max_state_num(fst):
	msn=0
	for i in range(len(fst)):
		if(fst[i][0]>msn):
			msn=fst[i][0]
		if(len(fst[i])>1):
			if(fst[i][1]>msn):
				msn=fst[i][1]
	return msn

with open(sys.argv[1],'r',encoding='utf8') as fin1, open(sys.argv[2],'r',encoding='utf8') as fin2:
	fst1=state_stringtoint([line.strip().split('\t') for line in fin1.readlines()])
	fst2=state_stringtoint([line.strip().split('\t') for line in fin2.readlines()])
	fst1msn=get_max_state_num(fst1)
	newfst=[]
	for i in range(len(fst1)):
		if(len(fst1[i])==1):
			newfst.append([fst1[i][0]])
		elif(len(fst1[i])==4):
			newfst.append([fst1[i][0],fst1[i][1],fst1[i][2],fst1[i][3]])

	newfst.append([0, fst1msn+1, '<eps>', '<eps>'])

	for i in range(len(fst2)):
		if(len(fst2[i])==1):
			newfst.append([fst2[i][0]+fst1msn+1])
		elif(len(fst2[i])==4):
			newfst.append([fst2[i][0]+fst1msn+1,fst2[i][1]+fst1msn+1,fst2[i][2],fst2[i][3]])
	
	newfst=add_transitions_back_to_zero(newfst)
	
	with open(sys.argv[3],'w',encoding='utf8') as fout:
		for i in range(len(newfst)):
			if(len(newfst[i])==1):
				fout.write("{}\n".format(newfst[i][0]))
			elif(len(newfst[i])==4):
				fout.write("{}\t{}\t{}\t{}\n".format(newfst[i][0],newfst[i][1],newfst[i][2],newfst[i][3]))
