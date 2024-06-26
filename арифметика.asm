.686P
.MODEL FLAT,C
.STACK
.DATA
.CODE

Public _Equation
_Equation proc a:dword, b:dword, c1:dword, x:dword, r:dword, s:dword, res:dword

   
    mov eax, 25
    imul b

    mov ebx, eax ; ebx = 25b
    xor eax, eax

    mov eax, 4
    imul c1
    imul a
    add eax, ebx
    xor ebx, ebx

    mov ebx, eax ; ebx = 25b + 4ac
    xor eax, eax

    mov eax, a
    mov ecx, 2
    imul a
    imul x
    cdq 
    idiv ecx
    add eax, ebx
    xor ebx, ebx
    xor ecx, ecx

    mov ebx, eax ; ebx = 25b + 4ac + x*a^2/2
    xor eax, eax

    mov eax, a
    mov ecx, 7
    imul ecx

    mov s, eax ; s = 7*a
    xor eax, eax

    mov eax, b
    cdq
    idiv s
    add eax, a

    mov r, eax ; r = b/(7a) + a
    xor eax, eax

    mov eax, 3
    imul x
    imul x
    sub eax, r
    
    mov ecx, eax ; ecx = 3x^2 –(b/(7a) +a)
    xor eax, eax

    mov eax, ebx
    cdq
    idiv ecx
    
    mov res, eax ; res = (25b +4ac +x*a^2 /2) / (3x^2 –(b/(7a) +a))
    ret
_Equation endp
end
