TITLE Project (main.asm)



INCLUDE Irvine32.inc

.data
    
    Menu BYTE "1. TEA-60 : 2. CHOCO-70 : 3. COFFEE-100 : 4.MOCHA-120 : ",0

	menu1 BYTE "1. TEA-60: ",0
	menu2 BYTE "2. CHOCO-70: ",0
	menu3 BYTE "3. COFFEE-100: ",0
	menu4 BYTE "4.MOCHA-120: ",0
    
	str0  BYTE  "*********************",0
	str1  BYTE  "PLEASE INPUT MONEY(ONLY 10, 20,50,100 SEN):",0
	str2  BYTE  "PLEASE CHOOSE ITEM YOU WANT: ENTER 1/2/3/4",0
	
	Money1 BYTE "10: ",0
	Money2 BYTE "20: ",0
	Money3 BYTE "50: ",0
	Money4 BYTE "100: ",0
	str3  BYTE  "YOUR MONEY: ",0
	str4  BYTE  "HERE IS YOUR TEA",0
	str5  BYTE  "HERE IS YOUR CHOCO",0
	str6  BYTE  "HERE IS YOUR COFFEE",0
	str7  BYTE  "HERE IS YOUR MOCHA",0
	str8  BYTE  "HERE IS YOUR CHANGE:  ",0
	str9  BYTE  "Thank You! Welcome Back",0
	mon10 DWORD ?
	mon20 DWORD ?
	mon50 DWORD ?
	mon100 DWORD ?
	monTotal DWORD ?
	
	choice DWORD ?
.code
main PROC
   
	mov edx, OFFSET str0		;"*****"
	call WriteString			;display str0
	call Crlf

	mov edx, OFFSET Menu		;"1,TEA........"
	call WriteString			;display Menu
	call Crlf

	mov edx, OFFSET str0
	call WriteString
	call Crlf
	call Crlf
	;---------put money------
	mov edx, OFFSET str1		;"Please input money"
	call WriteString			;display str2
	call Crlf
	call Crlf
	;------input 10 SEN money
	mov edx, OFFSET Money1		;"10: "
	call WriteString
	call ReadInt				;Read how many 10 into eax
	mov mon10, eax
	call Crlf
	

	;------get total10----
	; to get total 10*mon10(numbers of 10)
	
	mov eax, 10
	mov ebx, mon10
	mul ebx
	mov monTotal, eax 

	;------input 20 SEN money
	mov edx, OFFSET Money2		;"20....."
	call WriteString
	call ReadInt				;Read how many20 into eax
	mov mon20, eax
	call Crlf
	
	;-------get total money = total10+total20
	
	mov eax, 20
	mov ebx, mon20
	mul ebx
	add monTotal, eax 

	;-----input 50 SEN money
	mov edx, OFFSET Money3		;"50....."
	call WriteString
	call ReadInt
	mov mon50,eax
	call Crlf

	;------get total = total10 +total20 + total 50----
	
	mov eax, 50
	mov ebx, mon50
	mul ebx
	add monTotal, eax 

	;------input 100 SEN money---
	mov edx, OFFSET Money4		;"100..."
	call WriteString
	call ReadInt
	mov mon100, eax
	call Crlf
	
	;------get total = total10 + total20 + total50 + total100
	; to get total 10*mon10(numbers of 10)
	
	mov eax, 100
	mov ebx, mon100
	mul ebx
	add monTotal, eax 
	
	;-------Display total money
	mov edx, OFFSET str3  ;"YOUR MONEY: "
	call WriteString
	mov eax, monTotal
	call WriteDec
	call Crlf
	call Crlf
	;-----------choose item-----
	mov edx, OFFSET str2		;"Please choose what you'd like"
	call WriteString			;display str1
	call ReadInt				;Read choose number move into eax 

	mov choice, eax				;mov eax into choice

	;Now jump to item from what user input

	cmp  choice,1
	je   L1		;Jump L1 if cmp is equal
	jne  L2		;Jump L2 if cmp is not equal

L1:
	mov edx, OFFSET str4        ;"HERE IS YOUR TEA"
	call WriteString            ;display str4
	call Crlf					;go to next line
	
	sub monTotal, 60
	mov edx, OFFSET str8        ;"HERE IS YOUR CHANGE:  "
	call WriteString            ;display str8
	mov eax, monTotal			;the rest of money
	call WriteDec

L2:
	cmp choice, 2
	je L3
	jne L4
L3:
	mov edx, OFFSET str5       ;"HERE IS YOUR CHOCO"
	call WriteString            ;display str5
	call Crlf					;go to next line
	
	sub monTotal, 70
	mov edx, OFFSET str8        ;"HERE IS YOUR CHANGE:  "
	call WriteString            ;display str8
	mov eax, monTotal			;the rest of money
	call WriteDec

L4:
	cmp choice, 3
	je L5
	jne L6
L5:
	mov edx, OFFSET str6        ;"HERE IS YOUR COFFEE"
	call WriteString            ;display str6
	call Crlf					;go to next line
	
	sub monTotal, 100
	mov edx, OFFSET str8        ;"HERE IS YOUR CHANGE:  "
	call WriteString            ;display str8
	mov eax, monTotal			;the rest of money
	call WriteDec


L6:
	cmp choice, 4
	je L7
	jne L8
L7:
	mov edx, OFFSET str7        ;"HERE IS YOUR MOCHA"
	call WriteString            ;display str7
	call Crlf					;go to next line
	
	sub monTotal, 120
	mov edx, OFFSET str8        ;"HERE IS YOUR CHANGE:  "
	call WriteString            ;display str8
	mov eax, monTotal			;the rest of money
	call WriteDec
	
L8:
	call Crlf					;go to next line
	mov edx, OFFSET str9		;"Welcome Back",0
	call WriteString			;display str9
call Crlf
call WaitMsg
	exit
main ENDP

END main
