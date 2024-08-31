#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




void get_ip_byte(char *ip_address, char *bits_init, char *bits_2nd, char *bits_3rd, char *bits_4th)
{
	int bit_incr;
	int ip_incr;

	//Recuperation des octects de l'address
	    
    //Recuperqtion de la premiere octet
	ip_incr = 0;
    bit_incr = 0;
    while (ip_address[ip_incr] != '.')
    {
        bits_init[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_init[bit_incr] = '\0';
	//int_init_octet = atoi(bits_init);

    //recuperation de la 2eme octet
    bit_incr = 0;
    ip_incr++;
    while (ip_address[ip_incr] != '.')
    {
        bits_2nd[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_2nd[bit_incr] = '\0';
    //int_2nd_octet = atoi(bits_2nd);

    //recuperation de la 3eme octet
    bit_incr = 0;
    ip_incr++;
    while (ip_address[ip_incr] != '.')
    {
        bits_3rd[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_3rd[bit_incr] = '\0';
    //int_3rd_octet = atoi(bits_3rd);

    //recuperation de la 4eme octet
    bit_incr = 0;
    ip_incr++;
    while (ip_address[ip_incr] != '\0')
    {
        bits_4th[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_4th[bit_incr] = '\0';

}

int bit_to_dec(int bit)
{
    int *bin;
    char *char_bit;
    int incr;
    int dec = 0;

    char_bit = malloc(sizeof(char)*255);
    
    sprintf(char_bit, "%d", bit);
    
    bin = malloc(sizeof(int)*strlen(char_bit));

    incr = 0;
    while (incr != (int)strlen(char_bit))
    {
        bin[incr] = bit%10;
        bit = bit/10;
        incr++;
    }
    

    for (int i = strlen(char_bit); i >= 0; i--)
    {
        dec += (bin[i]*pow(2, i));
    }

    return dec;
}


void get_ip_byte_cidr(char *ip_address, char *bits_init, char *bits_2nd, char *bits_3rd, char *bits_4th, char *bits_cidr)
{
	int bit_incr;
	int ip_incr;

	//Recuperation des octects de l'address
	    
    //Recuperqtion de la premiere octet
	ip_incr = 0;
    bit_incr = 0;
    while (ip_address[ip_incr] != '.')
    {
        bits_init[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_init[bit_incr] = '\0';
	//int_init_octet = atoi(bits_init);

    //recuperation de la 2eme octet
    bit_incr = 0;
    ip_incr++;
    while (ip_address[ip_incr] != '.')
    {
        bits_2nd[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_2nd[bit_incr] = '\0';
    //int_2nd_octet = atoi(bits_2nd);

    //recuperation de la 3eme octet
    bit_incr = 0;
    ip_incr++;
    while (ip_address[ip_incr] != '.')
    {
        bits_3rd[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_3rd[bit_incr] = '\0';
    //int_3rd_octet = atoi(bits_3rd);

    //recuperation de la 4eme octet
    bit_incr = 0;
    ip_incr++;
    while (ip_address[ip_incr] != '/')
    {
        bits_4th[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_4th[bit_incr] = '\0';

    while (ip_address[ip_incr] != '\0')
    {
        bits_cidr[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_cidr[bit_incr] = '\0';
}

void netmask_cidr(char *ntmsk, char *bits_cidr)
{
    int int_bits_cidr;//cidr en binaire (int)
    int to_copy;
    int incr_ln, incr_col;  //ligne et col de la var "ntmsk_bin" (char)

    int dec_ntmsk[4];


    //initialisation de ntmsk_bin a '0'
    char ntmsk_bin[4][9]  = 
    {
        {'0', '0', '0', '0', '0','0', '0', '0', '\0'},
        {'0', '0', '0', '0', '0','0', '0', '0', '\0'},
        {'0', '0', '0', '0', '0','0', '0', '0', '\0'},
        {'0', '0', '0', '0', '0','0', '0', '0', '\0'}
    };

    int_bits_cidr = atoi(bits_cidr);

    //printf("\n\nint_bits_cidr = %d\n\n", int_bits_cidr);

    incr_ln = 0;
    
    while(int_bits_cidr > 0)
    {
        if (int_bits_cidr >= 8)
            to_copy = 8;
        else if (int_bits_cidr < 8)
            to_copy = int_bits_cidr;

        int_bits_cidr -= to_copy;

        for (incr_col = 0; incr_col < to_copy; incr_col++)
            ntmsk_bin[incr_ln][incr_col] = '1';
        incr_ln++;
    }

    for (int i = 0; i < 4; i++)
        dec_ntmsk[i] = bit_to_dec(atoi(ntmsk_bin[i]));
    
    sprintf(ntmsk, "%d.%d.%d.%d", dec_ntmsk[0], dec_ntmsk[1], dec_ntmsk[2], dec_ntmsk[3]);

}

void check_address_reseau(char *ip, char ip_class)
{
	char bits_init[255];
	char bits_2nd[255];
	char bits_3rd[255];
	char bits_4th[255];

	int bits_mask_init;
	int bits_mask_2nd;
	int bits_mask_3rd;
	int bits_mask_4th;

	int int_bits_init;
	int int_bits_2nd;
	int int_bits_3rd;
	int int_bits_4th;

	if (ip_class == 'E' || ip_class == 'D')
	{
		printf("Invalid: IP_class\n");
	}
	else if (ip_class == 'F')
	{
		printf("Invalid: IP\n");
	}
	else
	{
		get_ip_byte(ip, bits_init, bits_2nd, bits_3rd, bits_4th);

		int_bits_init = atoi(bits_init);
		int_bits_2nd = atoi(bits_2nd);
		int_bits_3rd = atoi(bits_3rd);
		int_bits_4th = atoi(bits_4th);

		if (ip_class == 'A')
		{
			bits_mask_init = int_bits_init & 255;
			bits_mask_2nd = int_bits_2nd & 0;
			bits_mask_3rd = int_bits_3rd & 0;
			bits_mask_4th = int_bits_4th & 0;

			printf("%d.%d.%d.%d\n", bits_mask_init, bits_mask_2nd, bits_mask_3rd, bits_mask_4th);
		}
		else if (ip_class == 'B')
		{
			bits_mask_init = int_bits_init & 255;
			bits_mask_2nd = int_bits_2nd & 255;
			bits_mask_3rd = int_bits_3rd & 0;
			bits_mask_4th = int_bits_4th & 0;

			printf("%d.%d.%d.%d\n", bits_mask_init, bits_mask_2nd, bits_mask_3rd, bits_mask_4th);
		}
		else if (ip_class == 'C')
		{
			bits_mask_init = int_bits_init & 255;
			bits_mask_2nd = int_bits_2nd & 255;
			bits_mask_3rd = int_bits_3rd & 255;
			bits_mask_4th = int_bits_4th & 0;

			printf("%d.%d.%d.%d\n", bits_mask_init, bits_mask_2nd, bits_mask_3rd, bits_mask_4th);
		}
		else
		{
			printf("Invalid: IP\n");
		}		
	}
}

int main()
{
    char ntmsk[255];
    netmask_cidr(ntmsk, "24");
    
    //printf( "",bit_to_dec());

    printf("Netmask: %s\n", ntmsk);
    
    printf("Adrress reseau: ");
    check_address_reseau("198.168.2.103", 'C');
 
    return 0;
}