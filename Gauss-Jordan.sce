//create matriz
A = [2,-7,-1;
    -3,-7,7;
    -1,7,-2], 
b = [-3;-4;-10]

A_aug = [A b]
a=A_aug
a=rref(a);

x=a(1,4)
y=a(2,4)
z=a(3,4)
