priority_queue<int> pq;
    for(int i=0;i<B.size();i++){
        pq.push(B[i]);
    }
    long long int answer = 0;
    for(int i=0;i<A;i++){
        answer+=pq.top();
        answer%=1000000009;
        pq.push(pq.top()/2);
        pq.pop();
    }
    return answer%1000000009;