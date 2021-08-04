// iterate through all submask of a mask
// iterate through all submask for every mask of n bits -> O(3 ^ n)

int mask;

for(int i = mask; i > 0; i = (i - 1) & mask) {
  // do something here
}
