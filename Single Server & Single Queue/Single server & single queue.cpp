#include <bits/stdc++.h>

using namespace std;

struct Entity
{
    int inter_arrival_time;
    int service_time;
    int id;
    int arrival_time;
    int begining_service_time;
    int end_service_time;
    int system_time;
    int waiting_time; // how  much time it waited in the queue
    int idle_time; // how much time the system was idle when this item has come
};

int main()
{
    freopen("input.txt", "r", stdin);

    int n, max_time;
    cin >> n;
    Entity items[n];

    for(int i=0; i<n; i++) {
        cin >> items[i].inter_arrival_time;
        cin >> items[i].service_time;
    }

    cin >> max_time;

    int last_index = -1;


    // prepare data for the simulation table
    for(int i=0; i<n; i++) {
        items[i].id = i+1;

        if(i==0) {
            items[i].arrival_time = items[i].inter_arrival_time;
            items[i].begining_service_time = items[i].arrival_time;
            items[i].end_service_time = items[i].begining_service_time + items[i].service_time;
            items[i].waiting_time = 0;
            items[i].system_time = items[i].waiting_time + items[i].service_time;
            items[i].idle_time = items[i].inter_arrival_time;
        }
        else {
            items[i].arrival_time = items[i-1].arrival_time + items[i].inter_arrival_time;
            if(items[i-1].end_service_time > items[i].arrival_time) {
                items[i].waiting_time = items[i-1].end_service_time - items[i].arrival_time;
                items[i].begining_service_time = items[i-1].end_service_time;
                items[i].idle_time = 0;
            }
            else {
                items[i].begining_service_time =items[i].arrival_time;
                items[i].waiting_time = 0;
                items[i].idle_time = items[i].begining_service_time - items[i-1].end_service_time;
            }

            items[i].end_service_time =  items[i].begining_service_time + items[i].service_time;
            items[i].system_time =  items[i].waiting_time + items[i].service_time;
        }

        if(last_index == -1) {
            if(items[i].end_service_time >= max_time) {
                last_index = i;
            }
        }
    }

    if(last_index == -1){
       last_index = n;
    }


    // print the simulation table
    printf("Arrival Num. | Arrival Time | Begin Sv. Time | End Sv. Time | Waiting Time | System Time | Idle Time\n");
    for(int i=0; i<n; i++) {
        printf("    %2d             %2d           %2d               %2d           %2d             %2d             %2d\n", items[i].id, items[i].arrival_time,
               items[i].begining_service_time, items[i].end_service_time, items[i].waiting_time, items[i].system_time, items[i].idle_time);
    }



    // calculate summary
    int total_system_time = 0;
    int item_count = 0;
    for(int i=0; i<= last_index; i++) {
        if(items[i].end_service_time <= max_time) {
            total_system_time += items[i].system_time;
            item_count++;
        }
    }

    double avg_system_time = (double) total_system_time / (double) item_count;

    cout << "Average System Time: " <<  avg_system_time << endl;

    // calculate Time Average Number in Queue Calculations
    int count = 0;
    for(int i=0; i<= last_index; i++) {
        if(items[i].waiting_time > 0) {
            for(int j = items[i].arrival_time; j < items[i].begining_service_time; j++) {
                if(j > max_time){
                    break;
                }
                count++;
            }
        }
    }

    double avg_time_number_in_q = (double) count / (double) max_time;

    cout << "Time Average Number in Queue: " << avg_time_number_in_q << endl;


    //Average Resource Utilization Calculations
    int total_idle_time = 0;

    for(int i=0; i<= last_index; i++) {
        if(items[i].idle_time > 0) {
            total_idle_time += items[i].idle_time;
        }
    }

    int total_utilized_time = max_time - total_idle_time;
    double avg_resource_utilization = (double) total_utilized_time / (double) max_time;

    cout << "Average Resource Utilization: " << avg_resource_utilization << endl;
    return 0;
}
