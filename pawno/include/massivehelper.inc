
/*
// ILYA SYSTEM 
new SQL_STRING[1250];
#define str_f(%0,%1) format(SQL_STRING, sizeof SQL_STRING, %0, %1), SQL_STRING
*/

new
	RETURN_STRING[10][2048];


stock String_UnPackMassive(Pack_Data[], UnPack_Data[][], unpack_format[] = "s[128]", unpack_separation[] = ",", len = sizeof UnPack_Data) 
{
	sscanf(Pack_Data, (str_f("p<%s>a<%s>[%d]", unpack_separation, unpack_format, len)), SQL_GET_ROW_STR);
	
	for new i; i < len; i++ do
		SetString(UnPack_Data[i], SQL_GET_ROW_STR[i]);

	return true;
}

stock Int_UnPackMassive(Pack_Data[], UnPack_Data[], unpack_format[] = "i", unpack_separation[] = ",", len = sizeof UnPack_Data)
	return (sscanf(Pack_Data, (str_f("p<%s>a<%s>[%d]", unpack_separation, unpack_format, len)), UnPack_Data));


stock Int_PackMassive_return(num = 0, Data[], len = sizeof Data)
{
	RETURN_STRING[num][0] = EOS;
	
	for new i; i < len; i++ do
	{
		strcat(RETURN_STRING[num], ( str_f("%d,", Data[i]) ) );
	}
}

#define Int_PackMassive(%0,%1) (Int_PackMassive_return(%0, %1), RETURN_STRING[%0])

stock Float_UnPackMassive(Pack_Data[], Float:UnPack_Data[], unpack_format[] = "f", unpack_separation[] = ",", len = sizeof UnPack_Data)
	return (sscanf(Pack_Data, (str_f("p<%s>a<%s>[%d]", unpack_separation, unpack_format, len)), UnPack_Data));
	
stock Float_PackMassive_return(num = 0, Float:Data[], len = sizeof Data)
{
	RETURN_STRING[num][0] = EOS;
	
	for new i; i < len; i++ do
	{
		strcat(RETURN_STRING[num], ( str_f("%f,", Data[i]) ) );
	}
}

#define Float_PackMassive(%0,%1) (Float_PackMassive_return(%0, %1), RETURN_STRING[%0])

stock String_PackMassive_return(num = 0, Data[][], len = sizeof Data)
{
	RETURN_STRING[num][0] = EOS;
	
	for new i; i < len; i++ do
	{
		strcat(RETURN_STRING[num], ( str_f("%s%s", Data[i], (len-1) == i ? "":",") ) );
	}
}

#define String_PackMassive(%0,%1) (String_PackMassive_return(%0, %1), RETURN_STRING[%0])