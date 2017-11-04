im=imread('/home/jedi/projects/lpr/image.jpg');
im=rgb2gray(im);
imshow(im);
getf('conv2.sci)
m_hr=[0.33, 0.33, 0.33]
im_hr=conv2(im, m_hr, 1)
imshow(mat2gray(im_hr));
sobel_hr=[-1, -2, -1; 0, 0, 0; -1, -2, -1]
E_hr=conv2(im_hr, sobel_hr, 1)
m_he=[-1, -1, -1; 0, 0, 0; 1, 1, 1]
m_ve=[-1, 0, 1; -1, 0, 1; -1, 0, 1]


function E = sobel(M, sobel_matrix)
  s=size(M)
  ss=size(sobel_matrix)
  E=M
  for i = 2:s(1)-1
    for j = 2:s(2)-1
       for si = -int(ss(1)/2):int(ss(1)/2)
          for sj = -int(ss(2)/2):int(ss(2)/2)
             E(i, j) = M(i+si, j+sj) * sobel(

function C = apply_threshold(M, t)
  s=size(M)
  C=M
  for i = 1:s(1)
    for j = 1:s(2)
        if M(i, j) > t then
           C(i, j) = 1
        else
           C(i, j) = 0
        end
    end
  end
endfunction

function N = normalize(M)
  s=size(M)
  nmax=M(1, 1)
  nmin=M(1, 1)
  N=M
  for i = 1:s(1)
    for j = 1:s(2)
      if nmax < M(i, j) then
        nmax = M(i, j)
      end
      if nmin > M(i, j) then
        nmin = M(i, j)
      end
    end
  end

  for i = 1:s(1)
    for j = 1:s(2)
      N(i, j) = (M(i, j) - nmin) / (nmax/255)
    end
  end
endfunction

m_hr=[1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9]
im_

im=imread('/home/jedi/projects/lpr/test_images/test_066.jpg');
im=rgb2gray(im);
E=edge(im, 'canny')
s=size(E)
p=zeros(1, s(1))
for j = 1:s(2)
  for i = 1:s(1)
    if E(i, j) == 1 then
        p(i) = p(i) + 1
    end
  end
end

function band_list = compute_bands(im)
  gray_im=rgb2gray(im);
  