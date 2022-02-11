pi RelativeFunctionBreakpoint("Solution2::isMatch", lineOffset=9)
  commands
    silent
    printf "=======================\n"
    printf "->i-1=%d,si-1=%d,i=%d,si=%d\n",i-1,s[i-1],i,s[i]
    printf "->j-1=%d,pj-1=%d,j=%d,pj=%d\n",j-1,p[j-1],j,p[j]
    pvector ans
    cont
  end
pi RelativeFunctionBreakpoint("Solution3::isMatch", lineOffset=5)
  commands
    printf "=======================\n"
    printf "->i=%d,ri=%d\n",i,ri
    printf "->j=%d,rj=%d\n",j,rj
    cont
  end
pi RelativeFunctionBreakpoint("Solution4::drs", lineOffset=1)
  commands
    printf "=======================\n"
    printf "->s=%c,p=%c\n",s,p
    cont
  end
pi RelativeFunctionBreakpoint("Solution4::dfs", lineOffset=1)
  commands
    printf "=======================\n"
    printf "->si=%d,pi=%d\n",si,pi
    cont
  end
