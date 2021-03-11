k, d, a = map(int, input().split('/'))
print(['gosu','hasu'][k+a < d or d == 0])
