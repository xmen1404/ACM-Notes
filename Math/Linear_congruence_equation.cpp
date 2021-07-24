// solution for eq: ax % m = b (x = unknown)
// if gcd(a, m) == 1 -> unique solution: x = b * inv(a) 
// if gcd(a, m) == p > 1 -> (a/p) * x % (m/p) = (b/p)
//      if b % p != 0 -> no solution
//      else (a/p) and (m/p) coprime -> solution x = x' (1st case)
//          there are p solutions: x = x' + k * (m/p) with k in [0, p-1]

// Other solution: Solve Diophantine equation: ax + k*m = b (x, k = unknowns)
