reset
set terminal png medium
set title "Root Approximation: Newton Method with Stationary Point"
set xrange [-1.5:2.5]
set yrange [-3:3]
set xzeroaxis
set yzeroaxis

p1(x) = x**3 - x**2 - x - 1
set output "images/newton.png"
set label 1 at 1,0.2
set label 1 "x" tc lt 1
set label 2 at 1,p1(1)-0.2
set label 2 "f(x)" tc lt 1
set arrow 1 from 1,0 to 1,p1(1) nohead lt 1
set object circle at first 1,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1,p1(1) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set arrow 2 from -1.5,p1(1) to 2.5,p1(1) nohead lt 1
plot p1(x) title 'x^3-x^2-x-1'

