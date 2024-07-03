#ifndef CRYPTAPI_H
#define CRYPTAPI_H

/*
	_Smiley:

	All fields were reverse-engineered by me from HLDS 3.1.0.7 (Linux).
	HLDS versions start numbering patches from 3 instead of 1, so you can literally take this as structures intended for 1.1.0.7 WON build.

	If the reverse-engineered fields have parameters specified, but the return type is void, then this may mean that most likely I did not reverse the return type and instead used void for the default stub.
	This is because from these function symbols you can only demangle the parameters, the return type can only be accurately extracted from DWARF info (if present) or presumably found by decompilers in tools like Ghidra.

	If param_ is specified in the name of the parameters, it means that this field was only reverse-engineered, e.g. do not have a reference in the SDKs, so we cannot know the actual name of parameters.
*/

typedef struct cryptapi_s
{
	int			size;
	int			unknown; // api version?
	void		(*Crypt_Initialize)(struct crypt_parms_s *param_1); // Crypt_Initialize__FP13crypt_parms_s
	void		(*Crypt_Shutdown)(void); // Crypt_Shutdown__Fv
	void		(*Crypt_ServiceAuthRefresh)(double param_1); // Crypt_ServiceAuthRefresh__Fd
	void		(*Crypt_GetRawBFKey)(void *param_1, void *param_2, int *param_3); // Crypt_GetRawBFKey__FPvT0Pi
	void		(*Crypt_DeleteAuthData)(struct authchallenge_s *param_1); // Crypt_DeleteAuthData__FP15authchallenge_s
	void		(*Crypt_GetConnectionKey)(void *param_1, int *param_2); // Crypt_GetConnectionKey__FPvPi
	void		(*Crypt_AuthRequest)(void *param_1, int param_2, struct authchallenge_s *param_3); // Crypt_AuthRequest__FPviP15authchallenge_s
	void		(*Crypt_AuthChallenge1)(void *param_1, int param_2, struct authchallenge_s *param_3); // Crypt_AuthChallenge1__FPviP15authchallenge_s
	void		(*Crypt_AuthChallenge2)(void *param_1, int param_2, struct authchallenge_s *param_3); // Crypt_AuthChallenge2__FPviP15authchallenge_s
	void		(*Crypt_AuthComplete)(void *param_1, int param_2, struct authchallenge_s *param_3); // Crypt_AuthComplete__FPviP15authchallenge_s
	void		(*Crypt_DecodeAuthComplete)(void *param_1, int param_2, struct authchallenge_s *param_3); // Crypt_DecodeAuthComplete__FPviP15authchallenge_s
	void		(*Crypt_GetUserId)(void); // Crypt_GetUserId__Fv
	void		(*Crypt_GetCertificate)(void *param_1, int *param_2); // Crypt_GetCertificate__FPvPi
	void		(*Crypt_GetNewCertificate)(void); // Crypt_GetNewCertificate__Fv
	void		(*Crypt_IsAuthenticated)(void); // Crypt_IsAuthenticated__Fv
	void		(*Crypt_GetAuthObject)(void); // Crypt_GetAuthObject__Fv
	void		(*Crypt_InstanceAuthObject)(void); // Crypt_InstanceAuthObject__Fv
	void		(*Crypt_DestroyAuthObject)(void); // Crypt_DestroyAuthObject__Fv
	void		(*Crypt_MD5_File)(unsigned char *param_1, char *param_2); // Crypt_MD5_File__FPUcPc
	void		(*Crypt_CreateKey)(int param_1, const unsigned char *param_2, void **param_3); // Crypt_CreateKey__FiPCUcPPv
	void		(*Crypt_DeleteKey)(void **param_1); // Crypt_DeleteKey__FPPv
	void		(*Crypt_Encrypt)(const void *param_1, const void *param_2, int param_3, void *param_4, int *param_5); // Crypt_Encrypt__FPCvT0iPvPi
	void		(*Crypt_Decrypt)(const void *param_1, const void *param_2, int param_3, void *param_4, int *param_5); // Crypt_Decrypt__FPCvT0iPvPi
} cryptapi_t;

#endif
