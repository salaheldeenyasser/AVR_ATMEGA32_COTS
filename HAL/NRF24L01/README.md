Features: 
Worldwide 2.4GHz ISM band operation
126 RF channels
1MHz non-overlapping channel spacing at 1Mbps
2MHz non-overlapping channel spacing at 2Mbps
Enhanced ShockBurst (fancy word for the following features) 
1 to 32 bytes dynamic payload length
Auto packet transaction handling
6 data pipe MultiCeiver
4-pin hardware SPI @ 10Mbps max 5V tolerant inputs (SPI pins only)
3 separate 32 bytes TX and RX FIFOs
For a full list of features see the datasheet.

*Part 1 : Registers*

The NRF24L01+ consists mostly of 8bit registers. In fact there are only 3 configuration registers that are 32bit. This implies that we will be using the SPI peripheral with 8bit data width. 

Ok now on to the registers. First up to the party is the configuration register, not sure why its called that when they are ALL mostly configuration registers. But nonetheless here it is: 

NOTE: ANY BIT DESIGNATED AS "RESERVED" IN ANY OF THE REGISTERS SHOULD BE LEFT TO ITS RESET VALUE OF '0'


Bit descriptions:
0 : PRIM_RX : Controls the NRF mode [ 1= Receiver ] [ 0 = Transmitter ]

1 : PWR_UP  : Power up control. [1 = Power up]  [0 = Power down]

2 : CRCO : Set CRC encoding scheme. [1 = 2 Bytes]  [0 = 1 Byte] I have a tutorial on CRC here if        you dont know what it is. 

3 : EN_CRC   : Enables the CRC (more on this later) If any channel has Auto Ack enabled the CRC is
also forced to be enabled. Ill explain why.

4 : MASK_MAX_RT : Enables/Disables whether the MAX_RT interrupt drives the IRQ pin

5 : MASK_TX_DS     : Enables/Disables whether the TX_DS interrupt drives the IRQ pin

6 : MASK_RX_DR    :  Enables/Disables whether the RX_DR interrupt drives the IRQ pin

Bits 0 and 1 are pretty self explanatory. Bit 2 controls how many bytes are used for the CRC scheme, basically the NRF will add either 1 or 2 bytes at the end of a transmission when CRC is enabled. And as noted when any channel has auto acknowledge enabled the CRC is forced. 

CRC and auto Ack work in conjunction to make sure data reception is only presented when the data is valid. The NRF will run a CRC algorithm on the address, packet control (if there is one) and your payload. The result of that is a "CRC code"  and it will add that code to the frame format and transmit it along with your data. Then the transmitter will turn itself into a receiver, no code required to do this, and listen for an ACK to verify the data was received.

The receiver will receive the entire frame packet and extract your data and run the same CRC algorithm on it. If the CRC code that results from the receivers CRC engine is the same as the one sent by the transmitter then it means they both ran the same CRC algorithm on the exact same data and thus no bits were lost or modified or noise etc.. therefore the data is valid. 

At this point the receiver will momentarily turn into a transmitter, all on its own no code required, and it will send an ACK command to the transmitter telling it that it received the data. If the CRC codes do not match then the receiver does not send anything and discards the data.
Note that both receiver and transmitter need to have auto ACK enabled for this scheme to work, this is what they call "Enhanced Shockburst" , see its just a fancy name.

Bits 4 to 6 are used to mask (enable/disable) different interrupts from affecting the IRQ pin. The IRQ pin is active low, when an interrupt happens and it is not masked out by these bits, the pin will go LOW signaling an interrupt condition has occurred and it would be up to software to then check the status register to see which interrupt is the one that was triggered.  
MASK_MAX_RT: (MAXIMUM RETRY)When the transmitter fails to receive an ACK from a receiver with auto ACK enabled, it will attempt to re-transmit the packet a specified number of times. Once that max number of tries is reached and still no ACK is received then the MAX_RT interrupt bit is set in the status register and if enabled by this bit the IRQ pin will go low.
MASK_TX_DS : (DATA SENT) This is used to mask the TX_DS from affecting the IRQ pin. The TX_DS interrupt signals that the data packet has been sent. If auto ACK is enabled then the interrupt will only trigger if the ACK is received. 
MSK_RX_DR : (DATA RECEIVED) This bit is used to mask the RX_DR interrupt from affecting the IRQ pin. The RX_DR interrupt signals that data has been received.
       [ 1 = Interrupt has no effect on IRQ pin ] [ 0 = Interrupt drives the IRQ pin low ]

Note that these bits are not the interrupts themselves, they only enable or disable the those interrupts from affecting the IRQ pin. The interrupts will happen no matter what and must be handled/cleared in order for the NRF to keep doing its job. They are cleared by writing a 1 to them in the status register.

A normal ShockBurst (just a fancy name indicating CRC is enabled) frame format looks like this and as you can see the CRC is added as the LSB


And if you are wondering, the Preamble is nothing more then a sequence of 1s and 0s to synchronize the receiver's demodulator to the incoming stream. It is only one byte long, if the first bit in the address is a 1 then the preamble is 10101010, otherwise it is 01010101.
___________________________________________________________________________________
And here are the rest of the registers, their names are in blue as they appear in the datasheet and in my code , minus the "Register" word obviously..



Bit descriptions: 
0 - 5 : This bits are used to enable auto acknowledge on the given pipe number. 

A "Pipe" is basically like a different channel but not a frequency channel, think of it as the name suggest a Pipe. Imagine one big Pipe where all the data comes through, this would be your frequency 2.4 Ghz give or take some megahertz because you have the option to change the frequency channels. Your data travels on this frequency and that is the BIG pipe so to speak. When it gets to the receiver it now can go down several other small pipes each with its own address. That is why when you transmit a data packet you send an address. More on that later. Got it? Good!!

___________________________________________________________________________________




0 - 5 : This bits are used to enable a given pipe number.

This is the register where you enable all pipes that you will be using. Setting a 1 in its corresponding bit enables it you can have more than one or all enabled at the same time.


___________________________________________________________________________________



This register only uses 2bits to set the width of the pipe addresses.  The values allowed are as follow:

00 - Illegal
01 - 3 bytes
10 - 4 bytes
11 - 5 bytes

Remember that the address is transmitted every time you send a packet so having less bytes to transmit can be beneficial in some applications but the robustness of having more bytes may be useful in other applications.
___________________________________________________________________________________


Bit descriptions:
0-3 : ARC : These bits are used to set how many times the transmitter will re-transmit when it fails to                         receive an auto ACK from the receiver.  

Acceptable values are:

0000 - re-transmit disabled
0001 - 1 re-transmit
0010 - 2 re-transmit
........ etc .......
1111 - 15 re-transmit


4-7 : ARD :  These bits are used to assign a designated waiting period before each re-transmission.

Acceptable values are:

0000 - Wait 250 uS
0001 - Wait 500 uS
0010 - Wait 750 uS
........ etc .......
1111 - Wait 4000 uS
___________________________________________________________________________________



This register uses bits 0 through 6 to set the channel frequency where your NRF will transmit and receive its data. Needless to say that both transmitter and receiver need to be on the same frequency. Also needless to say you get 126 RF channels to chose from. 000000 is not acceptable, hence why you dont have 127. 
___________________________________________________________________________________


Bit descriptions:
0    : Obsolete / Not used 

1-2 : RF_PWR : Set the output power in TX mode 

    Acceptable values are: 
    00 : -18dBm
    01 : -12dBm
    10 : -6dBm
    11 : 0dBm

3 : RF_DR_HIGH : Select one of the high data rates : [ 0 = 1Mbps ] [ 1 = 2Mbps ]

4 : PLL_LOCK : This bit is used for testing . Not relevant for operation. Leave at reset value of 0

5 : RF_DR_LOW : Set the data rate to its lowest of 250kbs, if this is set it overrides RF_DR_HIGH

6 : RESERVED

7 : CONT_WAVE :  This bit enables continuous transmission. 

The RF_PWR and PLL_LOCK bits should for the most part be left alone. The PLL_LOCK bit is used for a testing procedure explained in the datasheet, you ca view that on your ow. The RF_PWR bit controls the output power, if you do not know anything about analog electronics, 0dBm does not mean zero output power. Unless you have power consumption restrictions to meet you should not really set it below 0dBm.  

___________________________________________________________________________________



The big daddy and probably the register you will access the most is the Status register!!! Luckily everything here is pretty self explanatory. 

Bit descriptions:
0 : TX_FULL : When this bit is set it means the TX FIFO is full and you must either read some data or  risk it being lost as it pushes out the oldest data to fill it with new incoming data

1-3: RX_P_NO : Tells you on what Pipe there is the current data available to read.

4 : MAX_RT : This is an interrupt that signals when the maximum number of re-transmits has been    reached. Write a 1 to clear this bit

5 : TX_DS : Interrupt that signals when the data packet has been transmitted. If auto ACK is                  enabled his interrupt will only trigger when the ACK is received. Write 1 to clear

6 : RX_DR : This interrupt signals that new data has arrived to be read from the FIFO. Write 1 to            clear it.

Like stated in the CONFIG register description, these interrupts can drive the IRQ pin low when the flags are set. And like most status registers the interrupts are cleared by writing a 1 to the bit. 
___________________________________________________________________________________


Bit description:
0-3 : ARC_CNT : These bits tell current count of re-transmit

4-7 : PLOS_CNT : These bits keep track of how many packets have been lost after the max re-transmit

When ARC_CNT exceeds the max number of re-transmits set in the SETUP_RETR register it triggers the MAX_RT interrupt , which in turn may or may not trigger the IRQ pin to go low depending on your settings.

___________________________________________________________________________________



The RPD register has only one readable bit that signals power levels above -64dBm present in the RF channel you are using. Otherwise it reads 0.
___________________________________________________________________________________


If you look carefully, the image above depicts two registers, RX_ADDR_P0 and register RX_ADDR_P1.  This does not mean there are two registers in one, I am simply stating that both RX_ADDR_P0 and RX_ADDR_P1 have up to 5bytes (40 bits)  All these bits are used to set a unique address of your choice to Pipe 0 and Pipe 1. You do not have to use all 5 bytes but if you want to use 5 bytes these are the only two Pipes that support 5 byte of unique address space.
___________________________________________________________________________________


The rest of the Pipe's addresses only support a one byte address. The diagram above is also pretty self explanatory. 
Well technically speaking all the pipes addresses are 5 bytes but for these piepes you can only change the low byte, all the other 4 high bytes are equal to the high 4 bytes that are set in pipe 1  

___________________________________________________________________________________



This register is also 5bytes (40bits) long, I just got lazy to draw it like I drew the other long register. In this register you enter the address that has to match the pipe address on the receiver that listening. It does not have to be 5bytes long, since some pipes only support at one byte addresses. 

___________________________________________________________________________________


These 6 registers RX_PW_P0 ... through... RX_PW_P5  hold the number of bytes that are available to read on the specific pipe. 

___________________________________________________________________________________


Bit descriptions:
0 : RX_EMPTY : indicates there is no data in the RX FIFO

1 : RX_FULL : Indicates the RX FIFO is full...go figure 

4 : TX_EMPTY : Indicates TX FIFO is empty

5 : TX_FULL : take a wild guess......

6 : TX_REUSE : reuses / resend the previously sent TX payload (data packet)
___________________________________________________________________________________


When you transmit data as a transmitter to a receiver, both must agree on the payload length otherwise the receiver will not acknowledge the received payload. 

However this register allows you to send data of variable length without the need to have a predefined data width. each bit in this register enabled Dynamic Payload on a given pipe. However the Dynamic payload feature also must be enabled , in order for an individual pipe to also have dynamic payload. The feature is enabled in the next register. 

___________________________________________________________________________________



Bit descriptions:
0 : EN_DYN_ACK : Enables the NOACK feature

1 : EN_ACK_PAY : Allows the receiver to also send a payload along with an AUTO ACK

2 : EN_DPL : Enables dynamic payload

The EN_DYN_ACK bit means that the receiver does not have to send an ACK and the transmitter is also not expecting one. 
The auto ack sent by a receiver to tell the transmitter is usually does not include any payload , but you can do that if you would like by enabling the EN_ACK_PAY  bit. And ultimately EN_DPL is self explanatory.


One thing not discussed here are the RX and TX FIFO registers, that is because they are not directly accessible and have no address listed. The data fetches from them are all done by the NRF hardware when you send a read or write command. And that is the topic of the next post... the NRF supported commands.  


*Part 2 : Commands*

The NRF24L01+  and its few registers can be controlled by even fewer commands. There are only 11 commands you will need. Of those 11 commands you may never had the need for some of them, while others you will use and abuse.  It is important to remember the nature of the SPI protocol, that with every byte you send a byte is sent back. That first byte you get back is not the reply to the command request, but just a dummy byte that needs to be sent. Please get a refresher of SPI protocol as this is not an SI tutorial. 


On that note. The first byte the NRF send back after a command is sent is the continents of the STATUS register. But you should not just send any command because you simply want to read the status register, some commands will make the NRF wait for more data. You can use a NOP (NO operation) command if all you wish to do is read the status register. Ok now on to the list of command names and their opcodes.
___________________________________________________________________________________






The R_REGISTER command is used to Read a register and its opcode is 000xxxxx where the x's represent the address of the register you wish to read. For example if you want to read the contents of the RF_SETUP register which is address 0x06 ( 00000110 ) you would simply join the R_REGISTER command with the RF_SETUP address , which if you look at it ends up being just the RF_SETUP command anywyas.. then you send that through SPI and transmit. Then youll get a dummy byte, you can ignore it, to get your actual reply you need to send a dummy byte also because thats how SPI works and you will get the contents of the RF_SETUP register . 

Another way of stating it is that you should do a LOGICL OR operation of R_REGISTER with the address of the register you wish to read. However since the R_REGISTER command is basically 3 leading zeros...and the reaming bits will contain the address, it doesnt even change the address in any manner, so technically speaking to read a register you just send the address and it will reply with its content. the next command is not all zeros so it will indeed need to be ORed. 

Your code would look something like 

//pseudo code
#define R_REGISTER  0x00
#define RF_SETUP    0x06
spi_send ( R_REGISTER | RF_SETUP) ; 
//the returned byte will be first a dummy byte and then the contents
___________________________________________________________________________________



This is the Write command and you use it to write to a register. Unlike the previous command this is not just leading zeros. The x's represent the address of the register you want to write to. After sending this command the NRF expects the data that is to be written to . The SPI send would look exactly like the previous one except you OR it with W_REGISTER.

#define W_REGISTER  0x20  // 00100000
#define RF_SETUP    0x06
spi_send ( W_REGISTER | RF_SETUP) ;
spi_send(data)
.. ...
___________________________________________________________________________________

![image](https://github.com/salaheldeenyasser/AVR_ATMEGA32_COTS/assets/84989451/99c612d9-aa09-4c55-ace6-411e41088b57)


The R_RX_PAYLOAD is the command you send when you know you have received data, you will know this because the RX_DR interrupt will have been triggered.  Before you read the payload it makes sense to read STATUS register and check the  RX_P_NO bits to figure out which Pipe this data was received on. Or if you're only using one pipe it does not matter. After sending the R_RX_PAYLOAD command the NRF needs to transmit that data to you via SPI and in order to do that you have to send it some dummy bytes, it does not matter what the bytes are it can be 0xF1 or 0xFF... makes no difference, what does make a difference is that you need to send it the number of bytes equal to the data-width that was set in the RX_PW_P# register or alternatively there is a command to check the width of the top most payload. more on that further down. Width can be from 1 to 32 bytes. If this doesnt make sense its ok it shouldnt because I have not gone over the process of data reception and transmission but it will make sense, for now im describing registers and bits that still make no sense to you. 
___________________________________________________________________________________



This is the command to write your payload. You must make sure that before you start the RF transmission  the CE pin must be LOW. Once you send this command the NRF expects your payload data to come next. Your data width can be from 1 to 32 bytes longs.  After the last byte is sent and you stop the SPI communication you have to bring the CE pin HIGH, because a LOW to HIGH transition is what tells the NRF to transmit what is in the TX FIFO. and this command is what writes in the TX FIFO.
___________________________________________________________________________________




These two commands clear the FIFOs, really not much else to be said here aside from the fact that the datasheet says you should not clear the RX FIFO during a transmission of ACK.  Just wait till all transmissions are done before clearing the RX FIFO.
___________________________________________________________________________________



This command allows you to resend the last transmission. You do not need to send W_TX_PAYLOAD.
Simply send this command and it will resend the last packet so long as you have not flushed the FIFO with the commands above this one.
___________________________________________________________________________________



This command activates three features at once, not necessarily enables them, but allows them to be used if desired. So its very important. The features it activates are:
R_RX_PL_WID read RX payload width when using dynamic payload
W_ACK_PAYLOAD allows a payload to be sent with an ack
W_TX_PAYLOAD_NOACK disables ack on this specific packet
these three features are described below also. But those commands are useless unless they are activated by this command. 
The command works by first sending the ACTIVATE command, then sending the ACTIVATE_BYTE 
so basically sending 2 SPI send actions, first the ACTIVATE then the ACTIVATE byte.
___________________________________________________________________________________



This command  reads the data width of the top payload in the RX FIFO
___________________________________________________________________________________



This command is used to write the payload that will go along with an ACK, when ACK Payloads are enabled in the feature register. After this command the NRF expects the payload data which can be from 1 to 32 bytes.
___________________________________________________________________________________




This W_TX_PAYLOAD_NO_ACK command is used to disable auto ACK for the current packet. So you enabled this bit right before sending the W_TX_PAYLOAD command.
___________________________________________________________________________________



This is a No Operation command, when you send it the NRF does nothing with it. But since you are sending a byte the SPI has to send one back so the NRF send you the contents of its STATUS register. 
___________________________________________________________________________________

And that is all for the commands.
