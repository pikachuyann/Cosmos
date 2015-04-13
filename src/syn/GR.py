import math
import numpy as np
import matplotlib
matplotlib.use('Agg')
from matplotlib import pyplot as plt
import GPy
from scipy.special import erf
import os

kernel = GPy.kern.RBF(input_dim=1, variance=1., lengthscale=1.)

minv = 300
maxv = 1100

def get_my_string(fp):
   f = open(fp, 'r')
   string = str(f.read())
   f.close()
   return string


def sample(x):
    cmd="Cosmos"
    cmd += " /Users/benbot/Documents/Cosmos/Examples/Heart/idhp_model_heart_realtime_syn.slx"
    cmd += " /Users/benbot/Documents/Cosmos/Examples/Heart/nbBeat.lha"
    cmd += format(" --const \"SA_d=%f\""%x)
    cmd += " --max-run 250 --batch 0 --njob 2"
    print(cmd+"\n")
    os.system(cmd)
    os.system("grep -A 1 \"Total:\" Result.res | grep \"Estimated value\" | sed \"s/Estimated value:\t//g\" > tmpResult")
    v = eval(get_my_string("tmpResult"))
    return -v

"""def sample(x):
    return np.sin(10*x) + np.random.randn(1,1)*0.01"""

X = np.array([[minv],
       [ maxv]])

Y = np.array([[sample(minv)],
       [ sample(maxv)]])



def normpdf(x):
    return np.exp(-x*x/2)/np.sqrt(2*math.pi)

def normcdf(x):
    return (1+ erf(x/np.sqrt(2)))/2

def findMax(m,fmin):
    n = 1000
    X2 = np.linspace(minv,maxv,num=n).reshape((n,1))
    mu,s2 = m.predict(X2)
    t = np.argmax((fmin-mu) * normcdf( (fmin-mu)/np.sqrt(s2) ) + np.sqrt(s2)*normpdf( (fmin-mu)/np.sqrt(s2) ))
    t2 = minv + ( maxv - minv)*t/n
    return t2

def optstep(X,Y):
    m = GPy.models.GPRegression(X,Y,kernel)
    m.optimize_restarts(num_restarts = 10)
    nx = findMax(m,min(Y))
    X2 = np.vstack((X,nx))
    Y2 = np.vstack((Y,sample(nx)))
    return X2,Y2,m

for c in range(1,30):
    X,Y,m=optstep(X,Y)
    m.plot()
    plt.savefig(format('gaussfig%i'%c))
