function [B, D, l] = compute_pte(X, Y, Xp, Yp)
  B = [X' Y' ones(4,1) zeros(4, 3) -X'.*Xp -Y'.*Xp; ...
       zeros(4, 3) X' Y' ones(4,1) -X'.*Yp -Y'.*Yp ];
  //B = matrix (B', 8 , 8 )';
  D = [ Xp , Yp ];
  D = matrix (D, 8 , 1 );
  l = inv(B' * B) * B' * D;
endfunction

function [xp, yp] = warp(l, x, y)
  x=x/640
  y=y/640
  A = matrix([l(1:6)' 0 0 1 ],3,3)';
  C = [l(7:8)' 1];
  t = A*[x;y;1]/(C*[x;y;1]);
  xp = t(1)*640
  yp = t(2)*640
endfunction


function tryit(l)
  xlocate1=locate(1);
  x1=xlocate1(1)
  y1=xlocate1(2)
  xlocate2=locate(1);
  x2=xlocate2(1)
  y2=xlocate2(2)

  for u=0:.1:1,
    x = u*x1+(1-u)*x2;
    y = u*y1+(1-u)*y2;
    plot(x,y,'+b');
    [xp, yp] = warp(l, x, y)
    plot(xp, yp, 'ok')
  end
endfunction

function screen_phase1()
  xinit
  lines(0) // supress this silly "continue display"
  a = get("current_axes");
  a.data_bounds = [0,0;640,480]
  a.axes_visible = "on";
  a.box = "on"

  //Xlocate=locate(4)
endfunction

function screen_phase2(X, Y)
  a = get("current_axes");
  a.data_bounds = [-100,-100;900,580]
  plot([0;640;640;0;0], [0;0;480;480;0], "k")
  plot([X*640 X(1)*640], [Y*640 Y(1)*640])
endfunction

screen_phase1()
Xp = [0;   0; 640; 640]/640;
Yp = [0; 480; 480;   0]/640;
X = [120, 240, 508, 532]/640;
Y = [240, 373, 334, 190]/640;
[B, D, l] = compute_pte(X, Y, Xp, Yp)
screen_phase2()
tryit(l)
