
//Código en colaboración de compañeros de clase

ecuacionIzquierda= [3 -0.1 -0.2; 0.1 7 -0.3; 0.3 -0.2 10]
//ecuationMatrixLeftSide = [3 -0.1 -0.2; 0.1 7 -0.3; 0.3 -0.2 10]
ecuacionDer= [7.85;-19.3;71.4]
//ecuationMatrixRigthSide = [7.85;-19.3;71.4]
solutions = []

//Junta la parte izquierda y derecha
augmentedMatrix = [ecuacionIzquierda ecuacionDer]
[augmentedMatrixRowSize augmentedMatrixColSize] = size(augmentedMatrix)

//La matriz que se insertó
disp("Matriz insertada por el usuario")
disp(augmentedMatrix)

//Gaussian Elimination of variables over augmented Matrix to reduce it
for p = 1:1:augmentedMatrixRowSize-1
    pivot = augmentedMatrix(p,p);
    for i = p+1: 1: augmentedMatrixRowSize
        primFila = augmentedMatrix(i,p)
        augmentedMatrix(i, :) = augmentedMatrix(i, :) - (augmentedMatrix(p, :)/pivot)*primFila
    end
end

//Show the reduced Augmented matrix obtained
disp("Reduced Augmented Matrix")
disp(augmentedMatrix)

//Substition to find solutions to the ecuation system
solutions(augmentedMatrixRowSize) = augmentedMatrix(augmentedMatrixRowSize, augmentedMatrixColSize)/augmentedMatrix(augmentedMatrixRowSize, augmentedMatrixColSize-1)
for i = augmentedMatrixRowSize-1: -1: 1
    s = augmentedMatrix(i, augmentedMatrixColSize)
    for j = augmentedMatrixRowSize: -1: i
        s = s - augmentedMatrix(i, j)*solutions(j)
    end
    solutions(i) = s/augmentedMatrix(i, i)
end

//Accumulate variable solutions to the ecuation system
sol = ""
for i = 1: augmentedMatrixRowSize
    sol = sol +" var" + string(i) + " = " + string(solutions(i)) +","
end

disp("Ecuation Solutions")
disp(sol)
