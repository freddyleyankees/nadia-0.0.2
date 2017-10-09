
;Copyright (c) 2017
;@author kabon fredddy

;         ------------------------
;         --     BOOTLOADER     --
;         ------------------------

extern kprintf

global _start


jmp _start



;	 ----------------------------------------------------
;	 -	[object]										-
;	 -		[type]: function							-
;	 -		[name]:"_start"								-
;	 -		[arg]:none									-	
;	 -		[description]:								-
;	 -	[end]											-
;	 ----------------------------------------------------


_start:
	call cleanScreen
	
	
e:
	jmp e




msgSys: db 'loading system ...',10,0
msg: db 'starting kernel ...',10,0
empty:db ' ',0