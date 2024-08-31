#include <stdio.h>
#include <stdlib.h>
#include <string.h>




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

char class_ipv4(char *ip_address)
{
	
    // int ip_incr;
    // int bit_incr;
	//int err_incr_init_oct;
	int incr_ip;
	int incr_err_test;

    int int_init_octet;
    int int_2nd_octet;
    int int_3rd_octet;
    int int_4th_octet;

    char bits_init[255];
    char bits_2nd[255];
    char bits_3rd[255];
    char bits_4th[255];


    // ip_incr = 0;
    //input_incr = 0;
    
//errereur lors de la 
  	if (strlen(ip_address) > 15)
  	{
		return 'F';
	}
//Test si IP non absurde
	incr_ip = 0;
	incr_err_test = 0;
	while(incr_ip != (int)strlen(ip_address))
	{
		if(ip_address[incr_ip] == '.')
		{
			incr_err_test++;
		}
		incr_ip++;
	}
	
	if(incr_err_test != 3)
	{
		return 'F';
	}
	
	for(int i = 0; i < (int)strlen(ip_address); i++)
	{
		if(ip_address[i] == '.' && ip_address[i+1] == '.')
		{
			return 'F';
		}
	}
	
//Recuperation des octects de l'address
	
	get_ip_byte(ip_address, bits_init, bits_2nd, bits_3rd, bits_4th);
    
//---------------------------------------------------------------------------------------------
//Handdling error
	
	//bit_init
	if(strlen( bits_init ) == 1)
	{
		int incr_err_test;
		char tmp_bit;	//char temp pour stocket le bit
		
		incr_err_test = 0;
		
		tmp_bit = bits_init[0];
		
		//printf("\n\n\nbits_init[0] : %c\n\n\n\n", bits_init[0]);
		//printf("\n\n\ntmp_bit : %c", tmp_bit);
		
		bits_init[0] = '0';
		bits_init[1] = '0';
		bits_init[2] = tmp_bit; 
		
		//bit_init[] = {'0', '0', 'x'}
		
		for(int i = 48; i <= 57; i++)
		{
			if(bits_init[2] == i)
				incr_err_test++;
		}
		
		if(incr_err_test == 0)
		{
			return 'F';
		}
	}
	else if(strlen( bits_init ) == 2)
	{
		char tmp_bit[2];	//char temp pour stocket les bits
		int incr_err_test;
		
		tmp_bit[0] = bits_init[0];
		tmp_bit[1] = bits_init[1];
		
		bits_init[0] = '0';
		bits_init[1] = tmp_bit[0];
		bits_init[2] = tmp_bit[1];
	
		//bit_init[] = {'0', 'x', 'x'}
		incr_err_test = 0;
	
		for(int i = 48; i <= 57; i++)
		{
			for(int a = 1; a <= 2; a++)
			{
				if(bits_init[a] == i)
					incr_err_test++;
			}
		}
		
		if(incr_err_test == 0)
		{
			return 'F';
		}
		
	}
	else if(strlen(bits_init) == 3)
	{
		char tmp_bit[3];	//char temp pour stocket les bits
		int incr_err_test;
		
		tmp_bit[0] = bits_init[0];
		tmp_bit[1] = bits_init[1];
		tmp_bit[2] = bits_init[2];
		
		bits_init[0] = tmp_bit[0];
		bits_init[1] = tmp_bit[1];
		bits_init[2] = tmp_bit[2];
	
		//bit_init[] = {'x', 'x', 'x'}
		incr_err_test = 0;
	
		for(int i = 48; i <= 57; i++)
		{
			for(int a = 0; a <= 2; a++)
			{
				if(bits_init[a] == i)
					incr_err_test++;
			}
		}
		
		if(incr_err_test == 0)
		{
			return 'F';
		}
		
	}
	else if(strlen(bits_init) > 3)
	{
		return 'F';
	}
	
	//bits_2nd
	if(strlen(bits_2nd) == 1)
	{
		char tmp_bit;	//char temp pour stocket le bit
		int incr_err_test;
		
		tmp_bit = (char)bits_init[0];
		//strcat(tmp_bit, bits_init[0]);
		//strcmp(tmp_bit, bits_init);
		//printf("Valeur de tmp_bit : %c\n", tmp_bit);

		//printf("\n\n\nbits_2nd : %c\n\n\n", bits_2nd[0]);
		
		bits_2nd[0] = '0';
		bits_2nd[1] = '0';
		bits_2nd[2] = tmp_bit; 
		
		incr_err_test = 0;
		
		//for(int i = 48; i <= 57; i++)
		//{
			if(bits_2nd[2] != '0' || bits_2nd[2] != '1' || bits_2nd[2] != '2' || bits_2nd[2] != '3' || bits_2nd[2] != '4' || bits_2nd[2] != '5' || bits_2nd[2] != '6' || bits_2nd[2] != '7' || bits_2nd[2] != '8' || bits_2nd[2] != '9')
				incr_err_test++;
			else
			{
				;
			}
		//}
		
		if(incr_err_test != 1)
		{
			return 'F';
		}
		 
	}
	else if(strlen(bits_2nd) == 2)
	{
		char tmp_bit[2];	//char temp pour stocket les bits
		int incr_err_test;
		
		tmp_bit[0] = bits_init[0];
		tmp_bit[1] = bits_init[1];
		
		bits_2nd[0] = '0';
		bits_2nd[1] = tmp_bit[0];
		bits_2nd[2] = tmp_bit[1];
		
		incr_err_test = 0;
		
		//for(int i = 48; i <= 57; i++)
		//{
		for(int a = 1; a <= 2; a++)
		{
			if(bits_2nd[a] != '0' || bits_2nd[a] != '1' || bits_2nd[a] != '2' || bits_2nd[a] != '3' || bits_2nd[a] != '4' || bits_2nd[a] != '5'  || bits_2nd[a] != '6' || bits_2nd[a] != '7' || bits_2nd[a] != '8' || bits_2nd[a] != '9')
			{
				incr_err_test++;			
			}
		}
		//}
		
		if(incr_err_test != 2)
		{
			return 'F';
		}
		
	}
	else if(strlen(bits_2nd) == 3)
	{
		char tmp_bit[3];	//char temp pour stocket les bits
		int incr_err_test;
		
		tmp_bit[0] = bits_2nd[0];
		tmp_bit[1] = bits_2nd[1];
		tmp_bit[2] = bits_2nd[2];
		
		bits_2nd[0] = tmp_bit[0];
		bits_2nd[1] = tmp_bit[1];
		bits_2nd[2] = tmp_bit[2];
		
		incr_err_test = 0;
		
		for(int i = 48; i <= 57; i++)
		{
			for(int a = 0; a <= 2; a++)
			{
				if(bits_2nd[a] == i)
				{
					incr_err_test++;
				}
			}
		}
		
		if(incr_err_test != 3)
		{
			return 'F';
		}
	
	}
	
	//bits_3rd
	if(strlen(bits_3rd) == 1)
	{
		char tmp_bit;	//char temp pour stocket le bit
		int incr_err_test;
		
		tmp_bit = bits_3rd[0];
		
		bits_3rd[0] = '0';
		bits_3rd[1] = '0';
		bits_3rd[2] = tmp_bit;  
		
		incr_err_test = 0;
		
		for(int i = 48; i <= 57; i++)
		{
			if(bits_3rd[2] == i)
				incr_err_test++;
		}
		
		if(incr_err_test == 0)
		{
			return 'F';
		}
		
	}
	else if(strlen(bits_3rd) == 2)
	{
		char tmp_bit[2];	//char temp pour stocket les bits
		int incr_err_test;
		
		tmp_bit[0] = bits_3rd[0];
		tmp_bit[1] = bits_3rd[1];
		
		bits_3rd[0] = '0';
		bits_3rd[1] = tmp_bit[0];
		bits_3rd[2] = tmp_bit[1];
		
		incr_err_test = 0;
		
		for(int i = 48; i <= 57; i++)
		{
			for(int a = 1; a <= 2; a++)
			{
				if(bits_3rd[a] == i)
					incr_err_test++;
			}
		}
		
		if(incr_err_test == 0)
		{
			return 'F';
		}
		
	}
	else if(strlen(bits_3rd) == 3)
	{
		char tmp_bit[3];	//char temp pour stocket les bits
		int incr_err_test;
		
		tmp_bit[0] = bits_3rd[0];
		tmp_bit[1] = bits_3rd[1];
		tmp_bit[2] = bits_3rd[2];
		
		bits_3rd[0] = tmp_bit[0];
		bits_3rd[1] = tmp_bit[1];
		bits_3rd[2] = tmp_bit[2];
		
		incr_err_test = 0;
		
		for(int i = 48; i <= 57; i++)
		{
			for(int a = 0; a <= 2; a++)
			{
				if(bits_3rd[a] == i)
					incr_err_test++;
			}
		}
		
		if(incr_err_test == 0)
		{
			return 'F';
		}
		
	}
	
	//bits_4th
	if(strlen(bits_4th) == 1)
	{
		char tmp_bit;	//char temp pour stocket le bit
		int incr_err_test;
		
		tmp_bit = bits_4th[0];
		
		bits_4th[0] = '0';
		bits_4th[1] = '0';
		bits_4th[2] = tmp_bit;
		
		incr_err_test = 0;
		
		for(int i = 48; i <= 57; i++)
		{
			if(bits_4th[2] == i)
				incr_err_test++;
		}
		
		if(incr_err_test == 0)
		{
			return 'F';
		}
		 
	}
	else if(strlen(bits_3rd) == 2)
	{
		char tmp_bit[2];	//char temp pour stocket les bits
		int incr_err_test;
		
		tmp_bit[0] = bits_4th[0];
		tmp_bit[1] = bits_4th[1];
		
		bits_4th[0] = '0';
		bits_4th[1] = tmp_bit[0];
		bits_4th[2] = tmp_bit[1];
	
		incr_err_test = 0;
		
		for(int i = 48; i <= 57; i++)
		{
			for(int a = 1; a <= 2; a++)
			{
				if(bits_4th[a] == i)
					incr_err_test++;
			}
		}
		
		if(incr_err_test == 0)
		{
			return 'F';
		}
		
	}
	else if(strlen(bits_4th) == 3)
	{
		char tmp_bit[3];	//char temp pour stocket les bits
		int incr_err_test;
		
		tmp_bit[0] = bits_4th[0];
		tmp_bit[1] = bits_4th[1];
		tmp_bit[2] = bits_4th[2];
		
		bits_4th[0] = tmp_bit[0];
		bits_4th[1] = tmp_bit[1];
		bits_4th[2] = tmp_bit[2];
		
		incr_err_test = 0;
		
		for(int i = 48; i <= 57; i++)
		{
			for(int a = 1; a <= 2; a++)
			{
				if(bits_4th[a] == i)
					incr_err_test++;
			}
		}
		
		if(incr_err_test == 0)
		{
			return 'F';
		}
	
	}

	

//------------------------------------------------------------------------------------------------
    
    int_init_octet = atoi(bits_init);
    int_2nd_octet = atoi(bits_2nd);
    int_3rd_octet = atoi(bits_3rd);
    int_4th_octet = atoi(bits_4th);
    
    
    //teste de la classe
    if (int_init_octet > 255 || int_2nd_octet > 255 || int_3rd_octet > 255 || int_4th_octet > 255)
	{
		return 'F';
	}
    
    if (int_init_octet >= 0 && int_init_octet <= 127)
    {
		return 'A';
	}
    else if (int_init_octet >= 128 && int_init_octet <= 191)
    {
		return 'B';
	}
    else if (int_init_octet >= 192 && int_init_octet <= 223)
    {
		return 'C';
	}
    else if (int_init_octet >= 224 && int_init_octet <= 239)
    {
		return 'D'; 
	}
    else if (int_init_octet >= 240 && int_init_octet <= 255)
    {
		return 'E';
	}
	return 0;
}

void check_netmask(char ip_class)
{
	if (ip_class == 'A')
		printf("255.0.0.0\n");
	else if (ip_class == 'B')
		printf("255.255.0.0\n");
	else if (ip_class == 'C')
		printf("255.255.255.0\n");
	else if (ip_class == 'D' || ip_class == 'E')
		printf("Invlide: IP_class");
	else
		printf("Invlide: IP\n");
	
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

void check_broadcast(char *ip, char ip_class)
{
	char bits_init[255];
	char bits_2nd[255];
	char bits_3rd[255];
	char bits_4th[255];

	int bits_mask_init;
	int bits_mask_2nd;
	int bits_mask_3rd;

	int int_bits_init;
	int int_bits_2nd;
	int int_bits_3rd;

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

		if (ip_class == 'A')
		{
			bits_mask_init = int_bits_init & 255;

			printf("%d.255.255.255\n", bits_mask_init);
		}
		else if (ip_class == 'B')
		{
			bits_mask_init = int_bits_init & 255;
			bits_mask_2nd = int_bits_2nd & 255;

			printf("%d.%d.255.255\n", bits_mask_init, bits_mask_2nd);
		}
		else if (ip_class == 'C')
		{
			bits_mask_init = int_bits_init & 255;
			bits_mask_2nd = int_bits_2nd & 255;
			bits_mask_3rd = int_bits_3rd & 255;

			printf("%d.%d.%d.255\n", bits_mask_init, bits_mask_2nd, bits_mask_3rd);
		}
		else
		{
			printf("Invalid: IP\n");
		}		
	}


}

char *get_ip()
{
	char *ip = malloc(sizeof(char)*255);
	printf("Entrer l'address IP : ");
	scanf("%s", ip);

	return ip;
}

int main()
{
	char *ip;

	ip = malloc(sizeof(char)*255);

	ip = get_ip();
	printf("Netmask: ");
	check_netmask(class_ipv4(ip));
	printf("Addresse reseau: ");
	check_address_reseau(ip, class_ipv4(ip));
	printf("Addresse broadcast: ");
	check_broadcast(ip, class_ipv4(ip));

	return 0;
}
