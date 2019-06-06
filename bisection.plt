reset
set terminal png medium
set title "Root Approximation: Bisection"
set xrange [-1.5:2.5]
set yrange [-3:3]
set xzeroaxis
set yzeroaxis

set output "images/bisection1.png"
p1(x) = x**3 - x**2 - x - 1
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/bisection2.png"
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
set output "images/bisection3.png"
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
set output "images/bisection4.png"
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
set label 5 "m" tc lt 1
set label 6 at 1.1,p1(1)-0.1
set label 6 "f(m)" tc lt 1
set arrow 3 from 1,0 to 1,p1(1) nohead lt 1
set object circle at first 1,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1,p1(1) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/bisection5.png"
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
set output "images/bisection6.png"
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
set label 5 at 1.6,-0.1
set label 5 "m" tc lt 1
set label 6 at 1.6,p1(1.5)-0.1
set label 6 "f(m)" tc lt 1
set arrow 3 from 1.5,0 to 1.5,p1(1.5) nohead lt 1
set object circle at first 1.5,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.5,p1(1.5) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/bisection7.png"
set label 1 at 1.6,-0.1
set label 1 "a" tc lt 1
set label 2 at 1.6,p1(1.5)-0.1
set label 2 "f(a)" tc lt 1
set arrow 1 from 1.5,0 to 1.5,p1(1.5) nohead lt 1
set object circle at first 1.5,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.5,p1(1.5) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
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
set output "images/bisection8.png"
set label 1 at 1.6,-0.1
set label 1 "a" tc lt 1
set label 2 at 1.6,p1(1.5)-0.1
set label 2 "f(a)" tc lt 1
set arrow 1 from 1.5,0 to 1.5,p1(1.5) nohead lt 1
set object circle at first 1.5,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.5,p1(1.5) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
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
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/bisection9.png"
set label 1 at 1.85,-0.1
set label 1 "a" tc lt 1
set label 2 at 1.85,p1(1.75)-0.1
set label 2 "f(a)" tc lt 1
set arrow 1 from 1.75,0 to 1.75,p1(1.75) nohead lt 1
set object circle at first 1.75,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.75,p1(1.75) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
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
set output "images/bisection10.png"
set label 1 at 1.65,-0.1
set label 1 "a" tc lt 1
set label 2 at 1.50,p1(1.75)-0.1
set label 2 "f(a)" tc lt 1
set arrow 1 from 1.75,0 to 1.75,p1(1.75) nohead lt 1
set object circle at first 1.75,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.75,p1(1.75) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 3 at 2.1,-0.1
set label 3 "b" tc lt 1
set label 4 at 2.1,p1(2)-0.1
set label 4 "f(b)" tc lt 1
set arrow 2 from 2,0 to 2,p1(2) nohead lt 1
set object circle at first 2,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 2,p1(2) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set label 5 at 1.875,-0.1
set label 5 "m" tc lt 1
set label 6 at 1.675,p1(1.875)+0.2
set label 6 "f(m)" tc lt 1
set arrow 3 from 1.875,0 to 1.875,p1(1.875) nohead lt 1
set object circle at first 1.875,0 radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
set object circle at first 1.875,p1(1.875) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

clear
unset object
unset label
unset arrow
set output "images/bisection11.png"
set object circle at first 1.84,p1(1.84) radius char 0.5 fillstyle empty border lc rgb '#aa1100' lw 2
plot p1(x) title 'x^3-x^2-x-1'

