disp macro msg     		; definition of macro msg to display         
      mov ah, 09h  
      lea dx, msg  
      int 21h  
      endm  

 .model small   
 .stack 100h  

 .data 
 
 	str1 db 25 , ? , 25 dup('$')  	;stores accepted string
 	str2 db 25 , ? , 25 dup('$')   	;stores  string
      
 	msg1   db 10, 13, 'Menu $'  
 	msg2   db 10, 13, '1.Accept $'  
	msg3   db 10, 13, '2.Length $'  
 	msg4   db 10, 13, '3.Reverse $'  
 	msg5   db 10, 13, '4.Palindrome $'  
 	msg6   db 10, 13, '5.Exit $'  
 
	msg7   db 10, 13, 'Enter your choice : $'  
 	msg8   db 10, 13, 'Wrong choice $'  
 	msg9   db 10, 13, 'Enter The String : $'  
 	msg10  db 10, 13h, 'String is : $'  
 	msg11  db 10, 13, 'Length is : $'  
 	msg12  db 10, 13, 'The string is a palindrome  $'  
 	msg13  db 10, 13, 'The string is not a palindrome  $'
  

 .code   
      mov ax, @data     	; intialize data  segment  
      mov ds, ax  
menu :    disp msg1     	; display menu  
      	disp msg2      ;accept 
      	disp msg3      ;length
      	disp msg4      ;reverse
      	disp msg5      ;palindrome
      	disp msg6      ; exit
      	disp msg7     	; enter choice  
     
      	mov ah, 01h 	;accept choice from user 
      	int 21h  
;------------------------------------------------------------
      	mov bl, al     ; mov choice store in al to bl  
      	cmp bl, 31h    ; if choice=1  
      	je acc         ; jump if equal=1,jump on accept string  

      	cmp bl, 32h   	; if choice=2  
      	je  len        ; jump if equal=2 find lenth of string  
                                      
      	cmp bl, 33h    ; if choice=2      	
      je rev        	; jump if equal=3 find reverse string  
        
       	cmp bl, 34h    ;  jump if equal=4 find palindrome 
      	je pal         ; check if string is  palindrome 
 
      	cmp bl, 35h    ; if choice=5  
      	je  ter     	; jump if eqal. terminate or exit  
      
      disp msg4    	; wrong choice  
      	jmp menu    	;jump to label menu
;---------------------------------------------------------------
 		acc :	call accept  	;call procedure accept 
      			jmp menu  
;---------------------------------------------------------------
 		len :     call leng		;call procedure strlength  
      			jmp menu  
;---------------------------------------------------------------
 		rev :     call reverse	;call procedure reverse  
      			jmp menu
;---------------------------------------------------------------
 		pal:     	call pall		;call procedure palindrome  
      			jmp menu  
;---------------------------------------------------------------
 		ter:     mov ah, 4ch	;call terminate or exit  
      		    int 21h  
 
; ------------- procedure starts-   accept  procedure ----------
                                      
      accept proc near  
      	disp msg9  	;msg 9=enter the string
      	mov ah,0ah     ; accept string from user -using 0ah   
      	lea dx,str1    ;display string using dx
      int 21h  
     	ret  
 	accept endp 		;end of the procedure
 
 ;--------------------- length procedure -----------------------  
  
 	leng proc near	     	;procedure starts here
      	disp msg11          ;msg11=length is
		mov dl, str1+1     	; dl contains length of string- 						counter +1  
      	add dl, 30h  
      	mov ah, 02h         ; display length                           
      	int 21h  
      	ret   
 	leng endp
  
 ;--------------------- reverse procedure ----------------------
    
 	reverse proc near  	;procedure starts here
      	disp msg10  	;msg10=(reverse)string is
		xor ch, ch  	;initialize and -take char count in SI
		mov cl, str1+1 ;cl has length of string -take char 
;		count in SI 
      	sub cl, 01h  	;counter should -1 
		lea si, str1+2 ;sourse string with offset addrs  of 
;		str1
      	lea di, str1+2 ;destination string  with offset 
;					 address of str
		rep movsb 	; repeat while zero flag=0, mov str 					  byte by byte-copy to traverse till 					  end of first str  

      	mov cl, str1+1	;one byte to the right to find out 
;					 count 
      	lea di, str2+2 ; set counter for destination string  
 
      	loop1: mov  dx, [si] ; dx contains rightmost character  
                 mov [di], dx  ; copy character to destination  
      		  mov ah, 02h  
      		  int 21h 	 ; display character  
     
      	dec si  
      	inc di  
      	dec cl  
      	cmp cl,00h  	;if counter =0 stop
      	jne loop1  
      	ret 
 
 	reverse endp  


 ;-------------------- palindrome procedure --------------------    
 
      pall   proc  near  

		disp msg10  	; print msg10-string is
    		lea dx, str1+2	; str1 contains original string  
     
    		call reverse 	; str2 has reversed string   
      	lea di, str2+2 ; get starting address of di
      	;mov ah, 00h  
      	;mov dh, 00h  
      	lea si ,str1+2	; get starting address of a string  
      	mov cl,str1+1  ; cl contains length of string  

 		loop2 : mov al, byte ptr[si]  
      		   mov bl, byte ptr[di]  
      		   dec cl			; decrement count  
      		   cmp cl, 00h  	
      		   je loopx  
      		   cmp al, bl     	; compare characters  
      		   je  loop3       	; if same goto loop3  
 
		loopx : cmp cl, 00h ; if checked all characters  if 
;				  		  both character xero flg=1 
      		   je  loop4  
      		   disp msg13  ; the strings are not same - not 
;	 	                      palindrome
      		   jmp  loop5	  
 	
      	loop4 : disp msg12 ; the strings are same� palindrome
      
	 	loop5 : ret  
 	
      	loop3 : inc  si  
            	   inc   di  
     	   	   jmp  loop2      	; now check next character  
		   pall  endp
 end


