from scipy.sparse import coo_matrix
nele=30
nbus=40
col    = [ 2, 3, 6]
row    = [ 5, 5, 5]
val    = [ 0.1 + 0.1j, 0.1 - 0.2j, 0.1 - 0.4j]
test = coo_matrix((val, (row,col)), shape=(nele, nbus), dtype=complex)

print (test.col)

print (test.row)

print (test.data)
