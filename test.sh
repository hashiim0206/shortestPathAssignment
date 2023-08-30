# Sample program for testing: 
# https://github.com/education/autograding-example-c/tree/master


# Hint about printing color text in Terminal: 
# https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo "====================================="
echo "Running tests..."
echo "====================================="
echo

output=$(./shortest_path)
#expected_output="Hello, World!"
expected_output=" ============================================
|           Dijkstra's algorithm             |
|        (single-source shortest path)       |
|                                            |
|              Source vertex = 0             |
 --------------------------------------------
| Vertex | Distance | Path                   |
 --------------------------------------------
|      0 |        0 | 0 <- 0                 |
|      1 |        5 | 1 <- 0                 |
|      2 |        4 | 2 <- 0                 |
|      3 |        8 | 3 <- 1 <- 0            |
|      4 |       13 | 4 <- 2 <- 0            |
|      5 |       12 | 5 <- 3 <- 1 <- 0       |
 --------------------------------------------"



if [ $? -eq 0 ] ; then
  echo -e "${GREEN}PASS${NC}: Program exited zero"  
else
  echo -e "${RED}FAIL${NC}: Program did no exited zero"  
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo -e "${GREEN}PASS${NC}: Output is correct"  
else
  echo -e "${RED}FAIL${NC}: Output is incorrect"  
  echo 
  echo "Expected output:"  
  echo "$expected_output"
  echo 
  echo "Instead, output was:"
  echo "$output"
  exit 1
fi

echo
echo "All tests passed."

exit 0
