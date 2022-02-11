import code

def main():
	
	# read file
	f = open('q.csv')
	q_data = f.read()
	f.close()
	
	# each csv line
	q = []
	q_lines = q_data.splitlines()
	for r in range(0, len(q_lines)):
		q_line_str = q_lines[r].split(",")
		q_line = []
		for c in range(0, len(q_line_str)):
			q_line.append(int(q_line_str[c]))
		
		q.append(q_line)
	
	# reset candidate
	q_cand = resetCandidate(q)
	
	# first explore candidate
	exploreCandidate(q, q_cand)
	
	# expore loop
	while True:
		
		debugCheckPoint(q, q_cand, "confirmSingleCandidate()")
		
		# confirm single candidate
		confirmSingleCandidate(q, q_cand)
		
		# explore candidate
		exploreCandidate(q, q_cand)
		
		debugCheckPoint(q, q_cand, "confirmOnlyoneCandidate()")
		
		# confirm only-one candidate
		confirmOnlyoneCandidate(q, q_cand)
		
		# explore candidate
		exploreCandidate(q, q_cand)
		
#		print("press [Enter] , and next")
#		code.InteractiveConsole.raw_input("")
	
	
	

def debugCheckPoint(q, q_cand, nextFunc):
	
	print("== q ==")
	printData(q)
	print("")
	
	print("== q_cand raw line ==")
	printCandidate(q_cand)
	print("")
	
	print("press [Enter] , and next => " + nextFunc)
	code.InteractiveConsole.raw_input("")
	

def resetCandidate(q):
	q_cand = []
	
	# each raw
	for r in range(0, len(q)):
		q_cand_line = []
		
		# each column
		for c in range(0, len(q)):
			q_cand_rest = []
			
			# check existed number in q
			if (q[r][c] == 0):
				for i in range(1, len(q) + 1):
					q_cand_rest.append(i)
			
			q_cand_line.append(q_cand_rest)
		
		q_cand.append(q_cand_line)
	
	return q_cand

def exploreCandidate(q, q_cand):
	
	# each raw
	for r in range(0, len(q)):
		
		# each column
		for c in range(0, len(q)):
			
			# for blank cell
			if (len(q_cand[r][c]) > 0):
				
				### explore horizontal ###
				for i in range(0, len(q)):
					
					# through same cell
					if (i == c):
						continue
					
					# existed number in q
					if (q[r][i] > 0):
						
						# remove existed number
						for j in range(0, len(q_cand[r][c])):
							if (q[r][i] == q_cand[r][c][j]):
								q_cand[r][c].pop(j)
								break
				
				### explore vertical ###
				for i in range(0, len(q)):
					
					# through same cell
					if (i == r):
						continue
					
					# existed number in q
					if (q[i][c] > 0):
						
						# remove existed number
						for j in range(0, len(q_cand[r][c])):
							if (q[i][c] == q_cand[r][c][j]):
								q_cand[r][c].pop(j)
								break
				
				### explore square ###
				
				# square raw index
				sq_raw_index = r // 3
				# square column index
				sq_column_index = c // 3
				
				# square raw
				for sq_r in range(sq_raw_index * 3, (sq_raw_index + 1) * 3):
					
					# square column
					for sq_c in range(sq_column_index * 3, (sq_column_index + 1) * 3):
						
						# through same cell
						if ((r == sq_r) and (c == sq_c)):
							continue
						
						# existed number in q
						if (q[sq_r][sq_c] > 0):
							
							# remove existed number
							for i in range(0 , len(q_cand[r][c])):
								if (q[sq_r][sq_c] == q_cand[r][c][i]):
									q_cand[r][c].pop(i)
									break
	

def confirmSingleCandidate(q, q_cand):
	# each raw
	for r in range(0, len(q)):
		
		# each column
		for c in range(0, len(q)):
			
			# single candidate
			if (len(q_cand[r][c]) == 1):
				# confirm
				q[r][c] = q_cand[r][c][0]
				
				# remove candidate
				q_cand[r][c].pop(0)
	

def confirmOnlyoneCandidate(q, q_cand):
	# each raw
	for r in range(0, len(q)):
		
		# each column
		for c in range(0, len(q)):
			
			# each candidate number
			for i in range(0, len(q_cand[r][c])):
				
				# target number
				target_num = q_cand[r][c][i]
				
				### count horizontal ###
				target_count = 0
				for j in range(0, len(q)):
					
					# through same cell
					if (j == c):
						continue
					
					# check target candidate number existed
					if (target_num in q_cand[r][j]):
						target_count += 1
						break
				
				# only one => confirm
				if (target_count == 0):
					q[r][c] = target_num
					
					# clear target candidate numbers
					q_cand[r][c].clear()
					
					break
				
				### count vertical ###
				target_count = 0
				for j in range(0, len(q)):
					
					# through same cell
					if (j == r):
						continue
					
					# check target candidate number existed
					if (target_num in q_cand[j][c]):
						target_count += 1
						break
				
				# only one => confirm
				if (target_count == 0):
					q[r][c] = target_num
					
					# clear target candidate numbers
					q_cand[r][c].clear()
					
					break
				
				### count square ###
				target_count = 0
				
				# square raw index
				sq_raw_index = r // 3
				# square column index
				sq_column_index = c // 3
				
				# square raw
				for sq_r in range(sq_raw_index * 3, (sq_raw_index + 1) * 3):
					
					# square column
					for sq_c in range(sq_column_index * 3, (sq_column_index + 1) * 3):
						
						# through same cell
						if ((r == sq_r) and (c == sq_c)):
							continue
						
						# check target candidate number existed
						if (target_num in q_cand[sq_r][sq_c]):
							target_count += 1
							break
					
					if (target_count > 0):
						break
				
				# only one => confirm
				if (target_count == 0):
					q[r][c] = target_num
					
					# clear target candidate numbers
					q_cand[r][c].clear()
					
					break
			
			


def printData(q):
	for r in range(0, len(q)):
		print_line = "|"
		for c in range(0, len(q[r])):
			if (q[r][c] == 0):
				print_line = print_line + " |"
			else:
				print_line = print_line + str(q[r][c]) + "|"
		
		print(print_line)


def printCandidate(q_cand):
	# each raw
	for r in range(0, len(q_cand)):
		print("++++++++++")
		
		# each column
		for c in range(0, len(q_cand)):
			print_line = str(r) + "/" + str(c) + " :"
			for i in range(0, len(q_cand[r][c])):
				print_line = print_line + " " + str(q_cand[r][c][i])
			
			print(print_line)



if __name__ == '__main__':
	main()
