reset
set terminal png medium
set title "Root Approximation: Secant Method"
set xrange [-1.5:2.5]
set yrange [-3:3]
set xzeroaxis
set yzeroaxis

set output "images/newton1.png"
p1(x) = x**3 - x**2 - x - 1
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/newton2.png"
set label 1 at 1.51,0.2
set label 1 "x" tc lt 1
set label 2 at 1.52,p1(1.5)-0.2
set label 2 "f(x)" tc lt 1
set arrow 1 from 1.5,0 to 1.5,p1(1.5) nohead lt 1
set object circle at first 1.5,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.5,p1(1.5) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/newton3.png"
set label 1 at 1.51,0.2
set label 1 "x" tc lt 1
set label 2 at 1.52,p1(1.5)-0.2
set label 2 "f(x)" tc lt 1
set arrow 1 from 1.5,0 to 1.5,p1(1.5) nohead lt 1
set object circle at first 1.5,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.5,p1(1.5) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 3 at 2.031,0.2
set label 3 "x+1" tc lt 1
set object circle at first 2.031,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set arrow 2 from 1.5,p1(1.5) to 2.031,0 nohead lt 1
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/newton4.png"
set label 1 at 2.131,0.2
set label 1 "x" tc lt 1
set label 2 at 2.131,p1(2.031)-0.2
set label 2 "f(x)" tc lt 1
set arrow 1 from 2.031,0 to 2.031,p1(2.031) nohead lt 1
set object circle at first 2.031,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 2.031,p1(2.031) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/newton5.png"
set label 1 at 2.131,0.2
set label 1 "x" tc lt 1
set label 2 at 2.131,p1(2.031)-0.2
set label 2 "f(x)" tc lt 1
set arrow 1 from 2.031,0 to 2.031,p1(2.031) nohead lt 1
set object circle at first 2.031,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 2.031,p1(2.031) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 3 at 1.891,-0.2
set label 3 "x+1" tc lt 1
set object circle at first 1.891,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set arrow 2 from 2.131,p1(2.131) to 1.891,0 nohead lt 1
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/newton6.png"
set label 1 at 1.9,-0.1
set label 1 "x" tc lt 1
set label 2 at 1.95,p1(1.891)+0.1
set label 2 "f(x)" tc lt 1
set arrow 1 from 1.891,0 to 1.891,p1(1.891) nohead lt 1
set object circle at first 1.891,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.891,p1(1.891) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/newton7.png"
set label 1 at 1.9,-0.1
set label 1 "x" tc lt 1
set label 2 at 1.95,p1(1.891)+0.1
set label 2 "f(x)" tc lt 1
set arrow 1 from 1.891,0 to 1.891,p1(1.891) nohead lt 1
set object circle at first 1.891,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.891,p1(1.891) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 3 at 1.64,-0.2
set label 3 "x+1" tc lt 1
set object circle at first 1.84,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set arrow 2 from 1.891,p1(1.891) to 1.84,0 nohead lt 1
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/newton8.png"
set object circle at first 1.84,p1(1.84) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

