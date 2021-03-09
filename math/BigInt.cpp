namespace BigInt{
  using bigint = vector<int>;
  bigint strtobigint(string S){
    int N = SZ(S);
    bigint digit(N);
    REP(i,N){
      digit.at(i) = S.at(N-i-1)-'0';
    }
    while(SZ(digit)>1&&digit.back()==0)digit.pop_back();
    return digit;
  }
  string biginttostr(bigint digit){
    int N = SZ(digit);
    string str(N,'0');
    REP(i,N){
      str.at(i) += digit.at(N-i-1);
    }
    return str;
  }
  bigint carrt_ans_fix(bigint digit){
    int N = SZ(digit);
    REP(i,N-1){
      if(digit.at(i)>=10){
        int K = digit.at(i)/10;
        digit.at(i) %= 10;
        digit.at(i+1) += K;
      }
      if(digit.at(i)<0){
        int K = (-digit.at(i)-1)/10+1;
        digit.at(i) += K*10;
        digit.at(i+1) -= K;
      }
    }
    while(digit.back()>=10){
      int K = digit.back()/10;
      digit.back() %= 10;
      digit.PB(K);
    }
    while(SZ(digit)>1&&digit.back()==0)digit.pop_back();
    return digit;
  }
  bigint addtion(bigint a,bigint b){
    int N = max(SZ(a),SZ(b));
    bigint res(N);
    REP(i,N){
      res.at(i) = (i<SZ(a)?a.at(i):0)+(i<SZ(b)?b.at(i):0);
    }
    return carrt_ans_fix(res);
  }
  bigint substraction(bigint a,bigint b){
    int N = max(SZ(a),SZ(b));
    bigint res(N);
    REP(i,N){
      res.at(i) = (i<SZ(a)?a.at(i):0)-(i<SZ(b)?b.at(i):0);
    }
    return carrt_ans_fix(res);
  }
  bigint multiplication(bigint a,bigint b){
    int Na=SZ(a), Nb=SZ(b);
    bigint res(Na+Nb-1,0);
    REP(i,Na)REP(j,Nb){
      res.at(i+j) += a.at(i)*b.at(j);
    }
    return carrt_ans_fix(res);
  }
  int compare_bigint(bigint a,bigint b){
    int Na=SZ(a), Nb=SZ(b);
    if(Na>Nb) return 1;
    if(Na<Nb) return -1;
    REPR(i,Na){
      if(a.at(i)>b.at(i)) return 1;
      if(a.at(i)<b.at(i)) return -1;
    }
    return 0;
  }
  bigint divition(bigint a,bigint b){
    int Na=SZ(a), Nb=SZ(b);
    if(Na<Nb) return {0};
    int D = Na-Nb;
    bigint a_partial(a.begin()+D,a.end());
    if(compare_bigint(a_partial,b)>=0) D++;
    if(D == 0) return {0};
    bigint remain(a.begin()+(D-1),a.end());
    bigint ans(D);
    REPR(i,D){
      ans.at(i) = 9;
      CFOR(j,1,9){
        bigint x = multiplication(b,{j});
        if(compare_bigint(x,remain)==1){
          ans.at(j-1) = j-1;
          break;
        }
      }
      bigint result = multiplication(b,{ans.at(i)});
      remain = substraction(remain,result);
      if(i>=1){
        remain.insert(remain.begin(),a.at(i-1));
      }
    }
    return ans;
  }
  bigint remain(bigint a,bigint b){
    int Na=SZ(a), Nb=SZ(b);
    if(Na<Nb) return {0};
    int D = Na-Nb;
    bigint a_partial(a.begin()+D,a.end());
    if(compare_bigint(a_partial,b)>=0) D++;
    if(D == 0) return {0};
    bigint ans(a.begin()+(D-1),a.end());
    bigint div(D);
    REPR(i,D){
      div.at(i) = 9;
      CFOR(j,1,9){
        bigint x = multiplication(b,{j});
        if(compare_bigint(x,ans)==1){
          div.at(j-1) = j-1;
          break;
        }
      }
      bigint result = multiplication(b,{div.at(i)});
      ans = substraction(ans,result);
      if(i>=1){
        ans.insert(ans.begin(),a.at(i-1));
      }
    }
    return ans;
  }
}
