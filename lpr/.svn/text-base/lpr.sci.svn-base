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

function N = normalize_image(M)
  s=size(M)
  tmp=M
  N=M
  nmin=min(M)
  printf('nmin: %i\n', nmin)
  for i = 1:s(1)
    for j = 1:s(2)
      tmp(i, j) = (M(i, j) - nmin)
    end
  end

  nmax=max(tmp)
  printf('nmax: %i\n', nmax)
  for i = 1:s(1)
    for j = 1:s(2)
      N(i, j) = (tmp(i, j) / (nmax/255))
    end
  end

endfunction

function p = project(M, axis) 
  //axis = 'x' or 'y'
  if axis == 'y' then
    Mp = M
  else
    Mp = M'
  end
  s=size(Mp)
  p=zeros(1, s(1))
  for i = 1:s(1)
    for j = 1:s(2)
      p(i) = p(i) + Mp(i, j)
    end
  end
endfunction

function [p, band_list] = compute_bands(im)
  exec('conv2.sci')
  gray_im=rgb2gray(im);
  // apply vertical rank filter
  m_vr = [1/9; 1/9; 1/9; 1/9; 1/9; 1/9; 1/9; 1/9; 1/9]
  gray_im_vr = conv2(gray_im, m_vr, 1)
  // apply vertical edges detector
  m_ve = [-1, 0, 1; -1, 0, 1; -1, 0, 1]
  gray_im_ve = conv2(gray_im_vr, m_ve, 1)
  // normalize all this
  gray_im_ve_n = normalize_image(gray_im_ve)
  gray_im_ve = gray_im_ve_n
  // apply threashold to keep biggest edges
  gray_im_ve_threshold = apply_threshold(gray_im_ve, 130)
  imshow(mat2gray(gray_im_ve_threshold))
  p = project(gray_im_ve_threshold, 'y')
  
  //smooth projection with a rank filter
  m_rf = [ 1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9 ]
  p_smoothed = conv2(p, m_rf, 1)

  peaks = get_peaks(p_smoothed)
  // now get the bands using the peaks (ymin = p(peaks) * 0.55 with ymin < peaks)
  band_list=get_bands(p_smoothed, peaks)
  p = p_smoothed
endfunction

function peaks = get_peaks(p)
  peaks = list()
  s=size(p)
  window=(s(2)/10)/2
  printf('window: %i\n', window)
  deriv_previous = p(2*window) - p(1)
  for i = window+1:(s(2) - window)
    deriv = p(i+window) - p(i-window)
    if deriv < 0 & deriv_previous > 0 then
      peaks($+1) = i
    end
    deriv_previous = deriv
  end
endfunction

function bands = get_bands(p, peaks)
  s=size(peaks)
  p_size=size(p)
  bands = list()
  for e=peaks
    peak_bound = p(e) * 0.55 // 0.55 as described in anpr martinsky    
    for i = e:-1:1
      if p(i) < peak_bound then
        yb0 = i
        break
      end
    end

    for i = e:p_size(2)
      if p(i) < peak_bound then
        yb1 = i
        break
      end
    end
    bands($+1) = [yb0, yb1]
  end
endfunction
