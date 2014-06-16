000114cc:   ldr r3, [pc, #76]       ; (0x1151c) = 0x10001014 (UICR)
000114ce:   ldr r3, [r3, #0]        ; r3 = *(0x10001014) BOOTLOADER_START_ADDRESS is 0xFFFFFFFF
000114d0:   ldr r1, [pc, #76]       ; (0x11520) is 0xFFFFFFFF
000114d2:   cmp r1, r3
000114d4:   beq.n 0x114dc
000114d6:   ldr r0, [r3, #0]
000114d8:   cmp r0, r1
000114da:   beq.n 0x114c8
000114dc:   bne.n 0x114e8
000114de:   ldr r3, [pc, #68]       ; (0x11524)
000114e0:   ldr r0, [r3, #0]
000114e2:   ldr r1, [pc, #60]       ; (0x11520)
000114e4:   cmp r0, r1
000114e6:   beq.n 0x114c8
000114e8:   msr MSP, r0
000114ec:   ldr r1, [pc, #56]       ; (0x11528) 0x20002000 (SOFTDEVICE_RAM_END)
000114ee:   cmp r0, r1
000114f0:   ble.n 0x114fc
000114f2:   ldr r0, [pc, #56]       ; (0x1152c) 0x40000524 
000114f4:   ldr r2, [r0, #0]
000114f6:   movs r1, #2
000114f8:   orrs r2, r1
000114fa:   str r2, [r0, #0]
000114fc:   ldr r0, [pc, #48]       ; (0x11530) 0x0001057B
000114fe:   blx r0
00011500:   ldr r0, [pc, #48]       ; (0x11534) 0x000114B9
00011502:   blx r0
00011504:   ldr r0, [pc, #48]       ; (0x11538) 0x00011401
00011506:   bx r0
00011508:   subs r0, r2, r7
0001150a:   movs r0, #0
0001150c:   subs r0, r2, r7
0001150e:   movs r0, #0
00011510:   lsls r4, r5, #20
00011512:   ands r0, r0
00011514:   movs r4, r0
00011516:   movs r0, r0
00011518:   movs r0, r0
0001151a:   movs r0, #0
0001151c:   asrs r4, r2, #32
0001151e:   asrs r0, r0, #32
00011520:    ; <UNDEFINED> instruction: 0xffffffff
00011524:   ands r0, r0
00011526:   movs r1, r0
00011528:   movs r0, #0
0001152a:   movs r0, #0
0001152c:   lsls r4, r4, #20
0001152e:   ands r0, r0
00011530:   lsls r3, r7, #21
00011532:   movs r1, r0
00011534:   asrs r1, r7, #18
00011536:   movs r1, r0
00011538:   asrs r1, r0, #16
0001153a:   movs r1, r0
0001153c:   mrs r1, MSP
00011540:   ldr r0, [r1, #24]
00011542:   subs r0, #2