def SaveBatteryParams(handle, pardict):

	for key in pardict.keys():
		handle.write("double "+key+" = "+str(pardict[key])+";\n")

	return

def SaveBatteryFileHeader(handle, gK, gc, gC, gIR):

	handle.write("\n");

	handle.write("double gK"+" = "+str(gK)+";\n");
	handle.write("double gc"+" = "+str(gc)+";\n");
	handle.write("double gC"+" = "+str(gC)+";\n");
	handle.write("double gIR"+" = "+str(gIR)+";\n");

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

	handle.write("\tsrand (time(NULL));\n")
	handle.write("\tint idx = rand() % rt.size;\n")
	
	handle.write("\n");

	handle.write("\ttimeVal = rt.pt[idx].time;\n")
	handle.write("\tgCurrentReward = rt.pt[idx].reward/timeVal;\n")
	
	handle.write("\n");

	handle.write("\treturn timeVal;\n")
	handle.write("}\n")

	handle.write("\n");

	handle.write("double y1fun(double kc, double kmc, double t, double y10, double y20, double L)\n")
	handle.write("{\n")
	handle.write("\treturn (exp(-(t*(kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc)))/2)*(kc*((y20*(kc*kc + 6*kc*kmc + kmc*kmc) - 4*L*kc + 2*kc*kc*y10 - kc*kc*y20 + kmc*kmc*y20 - 2*kc*kmc*y10 - 2*kc*y10*sqrt(kc*kc + 6*kc*kmc + kmc*kmc) + 2*kmc*y20*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/(2*(kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc)) + (2*L*kc*exp(-(kc*t)/2)*exp((kmc*t)/2)*exp((t*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/2))/((kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc))) + kmc*((y20*(kc*kc + 6*kc*kmc + kmc*kmc) - 4*L*kc + 2*kc*kc*y10 - kc*kc*y20 + kmc*kmc*y20 - 2*kc*kmc*y10 - 2*kc*y10*sqrt(kc*kc + 6*kc*kmc + kmc*kmc) + 2*kmc*y20*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/(2*(kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc)) + (2*L*kc*exp(-(kc*t)/2)*exp((kmc*t)/2)*exp((t*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/2))/((kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc))) - ((y20*(kc*kc + 6*kc*kmc + kmc*kmc) - 4*L*kc + 2*kc*kc*y10 - kc*kc*y20 + kmc*kmc*y20 - 2*kc*kmc*y10 - 2*kc*y10*sqrt(kc*kc + 6*kc*kmc + kmc*kmc) + 2*kmc*y20*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/(2*(kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc)) + (2*L*kc*exp(-(kc*t)/2)*exp((kmc*t)/2)*exp((t*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/2))/((kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc)))*sqrt(kc*kc + 6*kc*kmc + kmc*kmc) + kc*exp((t*(kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc)))/2)*exp((t*(kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc)))/2)*((y20*(kc*kc + 6*kc*kmc + kmc*kmc) - 4*L*kc + 2*kc*kc*y10 - kc*kc*y20 + kmc*kmc*y20 - 2*kc*kmc*y10 + 2*kc*y10*sqrt(kc*kc + 6*kc*kmc + kmc*kmc) - 2*kmc*y20*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/(2*(kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc)) + (2*L*kc*exp(-(kc*t)/2)*exp((kmc*t)/2)*exp(-(t*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/2))/((kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc))) + kmc*exp((t*(kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc)))/2)*exp((t*(kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc)))/2)*((y20*(kc*kc + 6*kc*kmc + kmc*kmc) - 4*L*kc + 2*kc*kc*y10 - kc*kc*y20 + kmc*kmc*y20 - 2*kc*kmc*y10 + 2*kc*y10*sqrt(kc*kc + 6*kc*kmc + kmc*kmc) - 2*kmc*y20*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/(2*(kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc)) + (2*L*kc*exp(-(kc*t)/2)*exp((kmc*t)/2)*exp(-(t*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/2))/((kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc))) + exp((t*(kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc)))/2)*exp((t*(kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc)))/2)*((y20*(kc*kc + 6*kc*kmc + kmc*kmc) - 4*L*kc + 2*kc*kc*y10 - kc*kc*y20 + kmc*kmc*y20 - 2*kc*kmc*y10 + 2*kc*y10*sqrt(kc*kc + 6*kc*kmc + kmc*kmc) - 2*kmc*y20*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/(2*(kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc)) + (2*L*kc*exp(-(kc*t)/2)*exp((kmc*t)/2)*exp(-(t*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/2))/((kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(6*kc*kmc + kc*kc + kmc*kmc)))*sqrt(kc*kc + 6*kc*kmc + kmc*kmc)))/(2*kc);\n")
	handle.write("}\n")

	handle.write("\n");

	handle.write("double y2fun(double kc, double kmc, double t, double y10, double y20, double L)\n")
	handle.write("{\n")
	handle.write("\treturn exp(-(t*(kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc)))/2)*((y20*(kc*kc + 6*kc*kmc + kmc*kmc) - 4*L*kc + 2*kc*kc*y10 - kc*kc*y20 + kmc*kmc*y20 - 2*kc*kmc*y10 - 2*kc*y10*sqrt(kc*kc + 6*kc*kmc + kmc*kmc) + 2*kmc*y20*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/(2*(kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(kc*kc + 6*kc*kmc + kmc*kmc)) + exp((t*(kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc)))/2)*exp((t*(kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc)))/2)*((y20*(kc*kc + 6*kc*kmc + kmc*kmc) - 4*L*kc + 2*kc*kc*y10 - kc*kc*y20 + kmc*kmc*y20 - 2*kc*kmc*y10 + 2*kc*y10*sqrt(kc*kc + 6*kc*kmc + kmc*kmc) - 2*kmc*y20*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/(2*(kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(kc*kc + 6*kc*kmc + kmc*kmc)) + (2*L*kc*exp(-(kc*t)/2)*exp((kmc*t)/2)*exp(-(t*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/2))/((kc - kmc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))) + (2*L*kc*exp(-(kc*t)/2)*exp((kmc*t)/2)*exp((t*sqrt(kc*kc + 6*kc*kmc + kmc*kmc))/2))/((kmc - kc + sqrt(kc*kc + 6*kc*kmc + kmc*kmc))*sqrt(kc*kc + 6*kc*kmc + kmc*kmc)));\n")
	handle.write("}\n");

	handle.write("\n");

	handle.write("void enterActive(int id, double time)\n")
	handle.write("{\n")
	handle.write("\tgY1 = y1fun(gK/gc, gK/(1-gc), time-gTime, gY1, gY2, gCurrentReward);\n")
	handle.write("\tgY2 = y2fun(gK/gc, gK/(1-gc), time-gTime, gY1, gY2, gCurrentReward);\n")
	handle.write("\tgTime += time;\n")
	handle.write("}\n")

	handle.write("\n");

	handle.write("void enterIdle(int id, double time)\n")
	handle.write("{\n")
	handle.write("\tgY1 = y1fun(gK/gc, gK/(1-gc), time-gTime, gY1, gY2, gIR);\n")
	handle.write("\tgY2 = y2fun(gK/gc, gK/(1-gc), time-gTime, gY1, gY2, gIR);\n")
	handle.write("\tgTime += time;\n")
	handle.write("}\n")

	handle.write("\n")

	handle.write("bool isBatterieDepleted(void)\n")
	handle.write("{\n")
	handle.write("\treturn (gY1<0.0);\n")
	handle.write("}\n")

	return