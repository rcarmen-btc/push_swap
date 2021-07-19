# push_swap

```ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG && ./push_swap $ARG | wc -l && valgrind ./push_swap $ARG && echo $ARG```
<br/>
```AND```
<br/>
```ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG && ./push_swap $ARG | wc -l && echo $ARG```
