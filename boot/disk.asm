disk_load:
    pusha
    push dx

    mov ah, 0x02 ; ah <- int 0x13 function
    mov al, dh   ; al <- number of sectors to read
    mov cl, 0x02 ; cl <- sector
    mov ch, 0x00 ; ch <- cylinder
    ; dl <- drive number. Automatically set by BIOS
    mov dh, 0x00 ; dh <- head number

    int 0x13
    jc disk_error

    pop dx
    cmp al, dh    ; BIOS sets al to the number of sectors read.
    jne sectors_error
    popa
    ret


disk_error:
    mov bx, DISK_ERROR
    call print
    call print_nl
    mov dh, ah
	
    call print_hex
    jmp disk_loop

sectors_error:
    mov bx, SECTORS_ERROR
    call print

disk_loop:
    jmp $

DISK_ERROR: db "Disk read error", 0
SECTORS_ERROR: db "Incorrect number of sectors read", 0
