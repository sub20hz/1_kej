#include "pch.h"

#define svs (*((cg::serverStatic_t*)(0x1CBFC80)))

void PlayerCmd_GetButtonPressed(scr_entref_t arg)
{

	int32_t ent(0);
	cg::gentity_s* gent;
	if (HIWORD(arg)) {
		Scr_ObjectError("Not an entity");
		gent = NULL;
	}
	else {
		ent = LOWORD(arg);
		gent = Scr_GetEntity(arg);
		if (!gent->client) {
			Scr_ObjectError("Entity: [%i] is not a player", ent);
		}
	}
	if (Scr_GetNumParam() > 0)
		Scr_ObjectError("Usage: player GetButtonPressed()");

	//const cg::client_t* cl = &svs.clients[ent];
	//if (!cl || !gent) {
	//	Scr_ObjectError("Entity: [%i] is not a player", ent);
	//	return;
	//}
	const cg::usercmd_s* cmd = cg::cinput->GetUserCmd(cg::cinput->currentCmdNum - 1);

	if (!cmd) {
		Scr_AddInt(0);
		return;
	}
	Scr_AddInt(cmd->buttons);
}
void PlayerCmd_GetForwardMove(scr_entref_t arg)
{

	int32_t ent(0);
	cg::gentity_s* gent;
	if (HIWORD(arg)) {
		Scr_ObjectError("Not an entity");
		gent = NULL;
	}
	else {
		ent = LOWORD(arg);
		gent = Scr_GetEntity(arg);
		if (!gent->client) {
			Scr_ObjectError("Entity: [%i] is not a player", ent);
		}
	}
	if (Scr_GetNumParam() > 0)
		Scr_ObjectError("Usage: player GetForwardMove()");

	const cg::usercmd_s* cmd = cg::cinput->GetUserCmd(cg::cinput->currentCmdNum - 1);

	if (!cmd) {
		Scr_AddInt(0);
		return;
	}

	Scr_AddInt(cmd->forwardmove);
}
void PlayerCmd_GetRightMove(scr_entref_t arg)
{

	int32_t ent(0);
	cg::gentity_s* gent;
	if (HIWORD(arg)) {
		Scr_ObjectError("Not an entity");
		gent = NULL;
	}
	else {
		ent = LOWORD(arg);
		gent = Scr_GetEntity(arg);
		if (!gent->client) {
			Scr_ObjectError("Entity: [%i] is not a player", ent);
		}
	}
	if (Scr_GetNumParam() > 0)
		Scr_ObjectError("Usage: player GetRightMove()");

	const cg::usercmd_s* cmd = cg::cinput->GetUserCmd(cg::cinput->currentCmdNum - 1);

	if (!cmd) {
		Scr_AddInt(0);
		return;
	}

	Scr_AddInt(cmd->rightmove);
}
void PlayerCmd_SetVelocity(scr_entref_t arg)
{

	int32_t ent(0);
	cg::gentity_s* gent;
	vec3_t velocity{};
	if (HIWORD(arg)) {
		Scr_ObjectError("Not an entity");
		gent = NULL;
		return;
	}
	else {
		ent = LOWORD(arg);
		gent = Scr_GetEntity(arg);
		if (!gent->client) {
			Scr_ObjectError("Entity: [%i] is not a player", ent);
			return;
		}
	}
	if (Scr_GetNumParam() != 1)
		Scr_ObjectError("Usage: player setVelocity( vec3 )");

	Scr_GetVector(0, velocity);
	VectorCopy(velocity, gent->client->ps.velocity);
}

void GScr_WorldToScreen(scr_entref_t arg)
{
	if (Scr_GetNumParam() != 1) {
		Scr_ObjectError("Usage: WorldToScreen( end )");
		return;
	}
	vec3_t end;
	vec2_t screen;
	Scr_GetVector(0, end);

	bool success = r::WorldToScreen(end, screen);
	Scr_AddVector(vec3_t{ screen[0], screen[1], (float)success});

}
void GScr_WeaponExists(scr_entref_t arg)
{

	if (Scr_GetNumParam() != 1)
		Scr_ObjectError("Usage: player weaponExists( string )");

	char* weap = Scr_GetString(0);
	
	if (!weap) {
		Scr_AddInt(0);
		return;
	}
	int wpIdx = ((int(__cdecl*)(const char*))0x416610)(weap);

	Scr_AddInt(wpIdx > 0);
	

}
void GScr_GetEvarInt()
{
	if (Scr_GetNumParam() != 1)
		Scr_ObjectError("Usage: GetEvarInt( string )");

	char* _evar = Scr_GetString(0);

	evar_o* evar = Evar_FindByName(_evar);

	if (evar) {
		Scr_AddInt(evar->GetInt());
		return;
	}
	Scr_AddInt(0);
}
void GScr_GetEvarFloat()
{
	if (Scr_GetNumParam() != 1)
		Scr_ObjectError("Usage: GetEvarFloat( string )");

	char* _evar = Scr_GetString(0);

	evar_o* evar = Evar_FindByName(_evar);

	if (evar) {
		Scr_AddFloat(evar->GetFloat());
		return;
	}
	Scr_AddFloat(0);
}
void GScr_GetEvar()
{
	if (Scr_GetNumParam() != 1)
		Scr_ObjectError("Usage: GetEvar( string )");

	char* _evar = Scr_GetString(0);

	evar_o* evar = Evar_FindByName(_evar);


	if (evar) {
		char buf[64];

		switch (evar->type) {
		case EVAR_BOOL:
			if (snprintf(buf, sizeof(buf), "%i", evar->isEnabled()) > 0)
				Scr_AddString(buf);
			else Scr_AddString((char*)"");
			break;
		case EVAR_INT:
			if (snprintf(buf, sizeof(buf), "%i", evar->GetInt()) > 0)
				Scr_AddString(buf);
			else Scr_AddString((char*)"");
			break;
		case EVAR_FLOAT:
			if (snprintf(buf, sizeof(buf), "%f", evar->GetFloat()) > 0)
				Scr_AddString(buf);
			else Scr_AddString((char*)"");
			break;

		case EVAR_STRING:
			if (snprintf(buf, sizeof(buf), "%s", evar->GetString()) > 0)
				Scr_AddString(buf);
			else Scr_AddString((char*)"");
			break;
		default:
			Scr_AddString((char*)"");
			break;
		}
	
		return;
	}
	Scr_AddString((char*)"");
}
void Scr_LoadMethods()
{
	Scr_AddMethod("getbuttonpressed",	(xfunction_t)PlayerCmd_GetButtonPressed, false);
	Scr_AddMethod("getforwardmove",		(xfunction_t)PlayerCmd_GetForwardMove, false);
	Scr_AddMethod("getrightmove",		(xfunction_t)PlayerCmd_GetRightMove, false);
	Scr_AddMethod("setvelocity",		(xfunction_t)PlayerCmd_SetVelocity, false);

	Scr_AddFunction("weaponexists",		(xfunction_t)GScr_WeaponExists, false);
	Scr_AddFunction("worldtoscreen",	(xfunction_t)GScr_WorldToScreen, false);
	Scr_AddFunction("getevarint",		(xfunction_t)GScr_GetEvarInt, false);
	Scr_AddFunction("getevarfloat",		(xfunction_t)GScr_GetEvarFloat, false);
	Scr_AddFunction("getevar",			(xfunction_t)GScr_GetEvar, false);


}
xfunction_t Scr_GetFunction(const char** name, int* type)
{
	xfunction_t a = (xfunction_t)Scr_GetFunction_f(name, type);
	cg::scr_function_s* cmd = scr_functions;

	if (a)
		return a;

	else {
		if (!cmd)
			return 0;
		while (strcmp(*name, cmd->name)) {
			cmd = cmd->next;
			if (!cmd)
				return 0;

		}
		a = (xfunction_t)cmd->function;
		*name = cmd->name;
		Com_Printf(CON_CHANNEL_CONSOLEONLY, "^5Adding function: %s\n", cmd->name);

	}
	return a;
}
xmethod_t Player_GetMethod(const char** name)
{
	xmethod_t a = (xmethod_t)Player_GetMethod_f(name);
	cg::scr_function_s* cmd = scr_methods;

	if (a)
		return a;

	else
	{
		if (!cmd)
			return 0;
		while (strcmp(*name, cmd->name)) {
			cmd = cmd->next;
			if (!cmd)
				return 0;
			
		}
		a = (xmethod_t)cmd->function;
		*name = cmd->name;
		Com_Printf(CON_CHANNEL_CONSOLEONLY, "^2Adding method: %s\n", cmd->name);
	}
	return a;
}