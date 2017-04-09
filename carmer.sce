coef = input("Inserte los coeficientes de la matriz A ")
matriz = []
ext = []
for i = 1: coef
	for j = 1: coef
		matriz(i, j) = input("Coeficiente: A" + string(i) + string(j) + "= ")
	end
end
disp("Inserte los coeficientes de la matriz extendida")
for i = 1: coef
	ext(i) = input("Lado derecho" + string(i) + "= ")
end

detM = det(matriz)
[rX cX] = size(matriz)
sol = []

for i = 1: cX
	temp = matriz
	temp(:, i) = ext(:)
	disp("x" + string(i) + " = " + string(det(temp) / detM))
end
