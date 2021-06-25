```ARG=\`ruby -e "puts (1..500).to_a.shuffle.join(' ')"\`; ./push_swap $ARG | ./checker $ARG && ./push_swap $ARG | wc -l && echo $ARG```

OR

```make && ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG) | ./checker $(echo $ARG) ;  echo $ARG ;valgrind ./push_swap $(echo $ARG)```
