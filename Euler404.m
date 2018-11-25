
function [count, triples, m, Estimate] = Euler404(n)

a = @(p, q) (q ^ 2 + p * q - p ^ 2) * (p ^ 2 + 4 * p * q - q ^ 2);
triples = [];
count = 0;
m = [];
b = @(p, q) (p ^ 2 + q ^ 2) * (p ^ 2 + 4 * p * q - q ^ 2);
c = @(p, q) 2 * (p ^ 2 + q ^ 2) * (q ^ 2 + p * q - p ^ 2);
alpha = 1 / (sqrt(5) + 2);
beta = (sqrt(5) + sqrt(2)) / (sqrt(5) + 2 * sqrt(2));
gamma = beta - alpha;
max_a = 4.1029;
q_max = (n / max_a) ^ .25;
Estimate = gamma * q_max ^ 2;

for ell = 1:500
  for k = 1:ell
      %floor(alpha*ell):2*ceil(beta*ell)
      A = a(k, ell);
      B = b(k, ell);
      C = c(k, ell);
      if (A > 0 && A < n)
          %if( ( ell / ( sqrt(5) + 2 ) < k ) && ( k < ell * ( sqrt(5) + 2 ) / ( sqrt(5) + 4 ) ) )
          if (A < B && B < C && C < 2 * A)
              count += 1;
              triples = [triples; A, B, C];
              m = [m; k, ell];
          endif
          %endif
      endif
  endfor
endfor

endfunction
