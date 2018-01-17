%postavljanje max broja iteracija i prikaza iteracija
options = optimset('Display','iter');
options = optimset(options,'MaxIter',1000); 
open('model.slx')    
%trazenje minimuma
Q = fminsearch('ise',Qi,options)
    


    