# file a.out
# break generate

break 12
commands
silent
printf "----------\n"
printf "k is %d\n",k
bt
print str
continue
end

break 14 if k==0 
commands
silent
printf "push str to List\n"
print str
continue
end
