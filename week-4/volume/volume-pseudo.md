# pseudocode for volume.c

declare a constant based on the # of bytes in a .wav metadata

declare int with four argv: filename, input audio file, output audio file, factor to increase/decrease the vol

    validate CLI arg; if more or less than four

        issue warning
        exit
    
    declare input var with pointer = fopen(first CLI arg, "r" for read-only);
    
    validate if input file is legit; if NULL

        issue warning
        exit


    declare output var using pointer = fopen(second CLI arg, "w" for write access)
    // if it doesn't exist, w will create one

    validate if output file is legit; if NULL
        issue warning
        exit 

    // start copying metadata


    assign factor to variable; use atof (ASCII to float) to convert CLI arg into float

    create an array containing the metadata (header); data type is uint8_t, array # is based on the constant 

    use fread to read the data from input, from one element, totalling constant-amount of bytes, and saving it in header
    // note: this action moves the input file cursor forward by the constant-amount of bytes

    use fwrite to pass over the data from &header, for a total of constant-amount of bytes, from a single source, and saving it in output
    // note: this action moves the output file cursor forward by the constant-amount of bytes


    // move on to audio data
    // because of the cursor movement above, subsequent reads and writes will automatically start right after the metadata

    declare a variable (buffer) that will hold each byte of data during loop


    while (reading the file from input, the size is based on int16_t size, loop one at a time and assign it to  &buffer)

        adjust the volume by multiplying it using factor

        run fwrite

    flush out input
    flush out output

end