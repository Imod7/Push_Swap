import random
import os

def join_elem_oflist(lst):
	result = ""
	for item in lst:
		result += item
		result += " "
	return result

f=open('random_prng.txt', 'w')
lines = 0
group = 1
while group < 530:
	lines = 0
	while lines < 3:
		num = 0
		uniq_lst = []
		str_nums = ""
		while num < group:
			str_nums = str(random.randint(-4999, 5699))
			if str_nums not in uniq_lst:
				uniq_lst.append(str_nums)
				num += 1
		str_nums = join_elem_oflist(uniq_lst)
		# print(str_nums)
		f.write(str_nums)
		f.write("\n")
		lines += 1
	if group < 120:
		group += 1
	else:
		group += 50
f.close()

os.system("./test_script.sh random_prng.txt")