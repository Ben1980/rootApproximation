reset
set terminal png medium
set title "Root Approximation: Secant Method"
set xrange [-1.5:2.5]
set yrange [-3:3]
set xzeroaxis
set yzeroaxis

set output "images/secant1.png"
p1(x) = x**3 - x**2 - x - 1
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/secant2.png"
set label 1 at -0.1,0.2
set label 1 "a" tc lt 1
set label 2 at -0.2,p1(0)-0.2
set label 2 "f(a)" tc lt 1
set arrow 1 from 0,0 to 0,p1(0) nohead lt 1
set object circle at first 0,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 0,p1(0) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/secant3.png"
set label 1 at -0.1,0.2
set label 1 "a" tc lt 1
set label 2 at -0.2,p1(0)-0.2
set label 2 "f(a)" tc lt 1
set arrow 1 from 0,0 to 0,p1(0) nohead lt 1
set object circle at first 0,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 0,p1(0) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 3 at 2.1,-0.1
set label 3 "b" tc lt 1
set label 4 at 2.1,p1(2)-0.1
set label 4 "f(b)" tc lt 1
set arrow 2 from 2,0 to 2,p1(2) nohead lt 1
set object circle at first 2,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 2,p1(2) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/secant4.png"
set label 1 at -0.1,0.2
set label 1 "a" tc lt 1
set label 2 at -0.2,p1(0)-0.2
set label 2 "f(a)" tc lt 1
set arrow 1 from 0,0 to 0,p1(0) nohead lt 1
set object circle at first 0,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 0,p1(0) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 3 at 2.1,-0.1
set label 3 "b" tc lt 1
set label 4 at 2.1,p1(2)-0.1
set label 4 "f(b)" tc lt 1
set arrow 2 from 2,0 to 2,p1(2) nohead lt 1
set object circle at first 2,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 2,p1(2) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 5 at 1.1,-0.1
set label 5 "s" tc lt 1
set label 6 at 1.1,p1(1)-0.1
set label 6 "f(s)" tc lt 1
set arrow 3 from 1,0 to 1,p1(1) nohead lt 1
set object circle at first 1,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1,p1(1) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set arrow 4 from 0,p1(0) to 2,p1(2) nohead lt 1
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/secant5.png"
set label 1 at 1.1,-0.1
set label 1 "a" tc lt 1
set label 2 at 1.1,p1(1)-0.1
set label 2 "f(a)" tc lt 1
set arrow 1 from 1,0 to 1,p1(1) nohead lt 1
set object circle at first 1,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1,p1(1) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 3 at 2.1,-0.1
set label 3 "b" tc lt 1
set label 4 at 2.1,p1(2)-0.1
set label 4 "f(b)" tc lt 1
set arrow 2 from 2,0 to 2,p1(2) nohead lt 1
set object circle at first 2,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 2,p1(2) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/secant6.png"
set label 1 at 1.1,-0.1
set label 1 "a" tc lt 1
set label 2 at 1.1,p1(1)-0.1
set label 2 "f(a)" tc lt 1
set arrow 1 from 1,0 to 1,p1(1) nohead lt 1
set object circle at first 1,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1,p1(1) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 3 at 2.1,-0.1
set label 3 "b" tc lt 1
set label 4 at 2.1,p1(2)-0.1
set label 4 "f(b)" tc lt 1
set arrow 2 from 2,0 to 2,p1(2) nohead lt 1
set object circle at first 2,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 2,p1(2) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 5 at 1.77,-0.1
set label 5 "s" tc lt 1
set label 6 at 1.77,p1(1.67)-0.1
set label 6 "f(s)" tc lt 1
set arrow 3 from 1.67,0 to 1.67,p1(1.67) nohead lt 1
set object circle at first 1.67,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.67,p1(1.67) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set arrow 4 from 1,p1(1) to 2,p1(2) nohead lt 1
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/secant8.png"
set label 1 at 1.57,-0.1
set label 1 "a" tc lt 1
set label 2 at 1.45,p1(1.67)-0.1
set label 2 "f(a)" tc lt 1
set arrow 1 from 1.67,0 to 1.67,p1(1.67) nohead lt 1
set object circle at first 1.67,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.67,p1(1.67) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 3 at 2.1,-0.1
set label 3 "b" tc lt 1
set label 4 at 2.1,p1(2)-0.1
set label 4 "f(b)" tc lt 1
set arrow 2 from 2,0 to 2,p1(2) nohead lt 1
set object circle at first 2,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 2,p1(2) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/secant9.png"
set label 1 at 1.57,-0.1
set label 1 "a" tc lt 1
set label 2 at 1.45,p1(1.67)-0.1
set label 2 "f(a)" tc lt 1
set arrow 1 from 1.67,0 to 1.67,p1(1.67) nohead lt 1
set object circle at first 1.67,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.67,p1(1.67) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 3 at 2.1,-0.1
set label 3 "b" tc lt 1
set label 4 at 2.1,p1(2)-0.1
set label 4 "f(b)" tc lt 1
set arrow 2 from 2,0 to 2,p1(2) nohead lt 1
set object circle at first 2,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 2,p1(2) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 5 at 1.85,-0.1
set label 5 "m" tc lt 1
set label 6 at 1.85,p1(1.75)-0.1
set label 6 "f(m)" tc lt 1
set arrow 3 from 1.75,0 to 1.75,p1(1.75) nohead lt 1
set object circle at first 1.75,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.75,p1(1.75) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set arrow 4 from 1.67,p1(1.657) to 2,p1(2) nohead lt 1
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/secant10.png"
set object circle at first 1.84,p1(1.84) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

