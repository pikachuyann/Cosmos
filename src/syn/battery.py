def SaveBatteryParams(handle, pardict):

	for key in pardict.keys():
		handle.write("double "+key+" = "+str(pardict[key])+";\n")

	return

def SaveBatteryFileHeader(handle, gK, gc, gC, gIR, gAvgReward):

	handle.write("\n");

	handle.write("double gK"+" = "+str(gK)+";\n");
	handle.write("double gc"+" = "+str(gc)+";\n");
	handle.write("double gC"+" = "+str(gC)+";\n");
	handle.write("double gIR"+" = "+str(gIR)+";\n");
	handle.write("double gAvgReward"+" = "+str(gAvgReward)+";\n");

	handle.write("\n");

	handle.write("double gCurrentReward = 0.0;\n");
	handle.write("double gTime = 0.0;\n");
	handle.write("double gY1 = (1-gc)*gC;\n");
	handle.write("double gY2 = gc*gC;\n");

	handle.write("\n");

	handle.write("struct TimeReward\n");
	handle.write("{\n");
	handle.write("\tdouble time;\n");
	handle.write("\tdouble reward;\n");
	handle.write("};\n");

	handle.write("\n");

	handle.write("struct RetValTR\n");
	handle.write("{\n");
	handle.write("\tTimeReward * pt;\n");
	handle.write("\tunsigned int size;\n");
	handle.write("};\n");
	handle.write("\n");
	return 

def SaveBatteryDistribution(handle, dData):

	dIdCurr = {}
	for key, valone, valtwo in dData:
		dIdCurr.setdefault(key, []).append([valone, valtwo])

	for key in dIdCurr:
		handle.write("TimeReward tr"+str(key)+"[] = { ");
		llen = len(dIdCurr[key])
		cnt = 0;
		ll = dIdCurr[key]
		for elem in ll:
			handle.write("{"+str(elem[1])+", "+str(elem[0])+"}");
			cnt = cnt + 1
			if cnt!=llen:
				handle.write(", ");
		handle.write("};\n");
	

	handle.write("\n")	
	handle.write("RetValTR RetStruct(int id)\n")
	handle.write("{\n")
	handle.write("\tRetValTR ret = {NULL,0};\n")

	handle.write("\n")

	handle.write("\tswitch(id) {\n")
	for key in dIdCurr:
		handle.write("\t\tcase "+str(key)+":\n")
		handle.write("\t\t\tret.pt = & tr"+str(key)+"[0];\n")
		handle.write("\t\t\tret.size = sizeof(tr"+str(key)+")/(sizeof(double)*2);\n")
		handle.write("\t\t\tbreak;\n")

	handle.write("\t}\n")
	handle.write("\n")
	handle.write("\treturn ret;\n")
	handle.write("}\n")


	SaveBatteryFooter(handle)	
	return


def SaveBatteryFooter(handle):
	handle.write("\n");

	handle.write("double TransitionTime(int id)\n")
	handle.write("{\n")
	handle.write("\tdouble timeVal = 0.0;\n");
	handle.write("\tRetValTR rt = RetStruct(id);\n")
	
	handle.write("\n");

	handle.write("\tif (!rt.size)\n")
	handle.write("\t\t return gAvgReward;\n")
	handle.write("\n");

	handle.write("\tint idx = rand() % rt.size;\n")
	
	handle.write("\n");

	handle.write("\ttimeVal = rt.pt[idx].time;\n")
	handle.write("\tgCurrentReward = rt.pt[idx].reward/timeVal;\n")
	
	handle.write("\n");

	handle.write("\treturn timeVal;\n")
	handle.write("}\n")

	handle.write("\n");

	handle.write("double y1fun(double c, double kp, double k, double t, double y0, double y10, double y20, double I)\n")
	handle.write("{\n")
	#handle.write("\tcerr<<\"Battery state: \"<<y10<<\" \"<<y20<<\" \"<<I<<\" \"<<t<<endl;")
	handle.write("\n")
	handle.write("\treturn y10*exp(-kp*t)+(y0*kp*c-I)*(1-exp(-kp*t))/kp-I*c*(kp*t-1+exp(-kp*t))/kp;\n")
	handle.write("}\n")

	handle.write("\n");

	handle.write("double y2fun(double c, double kp, double k, double t, double y0, double y10, double y20, double I)\n")
	handle.write("{\n")
	#handle.write("\tcerr<<\"Battery state: \"<<y10<<\" \"<<y20<<\" \"<<I<<\" \"<<t<<endl;")
	handle.write("\n")
	handle.write("\treturn y20*exp(-kp*t)+y0*(1-c)*(1-exp(-kp*t))-I*(1-c)*(kp*t-1+exp(-kp*t))/kp;\n")
	handle.write("}\n");

	handle.write("\n");

	handle.write("void enterActive(int id, double time)\n")
	handle.write("{\n")

	handle.write("\tif (time==gTime || gCurrentReward==0.0) return;\n")
	handle.write("\n");
	handle.write("\tgY1 = y1fun(gc, gK/(gc*(1-gc)), gK, (time-gTime)/1000.0, gY1+gY2, gY1, gY2, gIR);\n")
	handle.write("\tgY2 = y2fun(gc, gK/(gc*(1-gc)), gK, (time-gTime)/1000.0, gY1+gY2, gY1, gY2, gIR);\n")
	handle.write("\tgTime = time;\n")
	handle.write("}\n")

	handle.write("\n");

	handle.write("void enterIdle(int id, double time)\n")
	handle.write("{\n")
	handle.write("\tif (time==gTime || gCurrentReward==0.0) return;\n")
	handle.write("\n");	
	handle.write("\tgY1 = y1fun(gc, gK/(gc*(1-gc)), gK, (time-gTime)/1000.0, gY1+gY2, gY1, gY2, gCurrentReward);\n")
	handle.write("\tgY2 = y2fun(gc, gK/(gc*(1-gc)), gK, (time-gTime)/1000.0, gY1+gY2, gY1, gY2, gCurrentReward);\n")
	handle.write("\tgTime = time;\n")
	handle.write("}\n")

	handle.write("\n")

	handle.write("bool isBatterieDepleted(void)\n")
	handle.write("{\n")
	handle.write("\treturn (gY1<0.0);\n")
	handle.write("}\n")

	handle.write("\n")

	handle.write("bool ResetBatteryState(void)\n")
	handle.write("{\n")
	handle.write("\tgCurrentReward = 0.0;\n");
	handle.write("\tgTime = 0.0;\n");
	handle.write("\tgY1 = (1-gc)*gC;\n");
	handle.write("\tgY2 = gc*gC;\n");
	handle.write("\tsrand (time(NULL));\n")
	handle.write("}\n")

	handle.write("\n")

	return