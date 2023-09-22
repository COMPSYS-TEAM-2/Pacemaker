import csv

AVI_VALUE = 300
AEI_VALUE = 800
PVARP_VALUE = 50
VRP_VALUE = 150
LRI_VALUE = 950
URI_VALUE = 900

def main():
    file = open('test-4.csv', 'r+')

    # Define all of the timers
    atov = 0
    vtoa = 0
    atoa = 0
    vtov = 0

    atovCounts = []
    vtoaCounts = []
    atoaCounts = []
    vtovCounts = []

    # Define variables to count state

    csvReader = csv.DictReader(file)

    for col in csvReader:
        # Increment the timers
        atov += 1
        vtoa += 1
        atoa += 1
        vtov += 1
        # If there is an atrium event
        if (int((col[' A']).strip()) == 1 or int((col[' A']).strip()) == -1):
            # First two second can be ignored
            if (float(col['Time']) > 2000):
                vtoaCounts.append(vtoa)
                atoaCounts.append(atoa)
            atov = 0
            atoa = 0

        if (int((col[' V']).strip()) == 1 or int((col[' V']).strip()) == -1):
            # First two second can be ignored
            if (float(col['Time']) > 2000):
                atovCounts.append(atov)
                vtovCounts.append(vtov)
                
            vtoa = 0
            vtov = 0

    print("A to V counts", atovCounts)
    print("V to A counts", vtoaCounts)
    print("A to A counts", atoaCounts)
    print("V to V counts", vtovCounts)

    aveAtoV = 0
    aveVtoA = 0
    aveAtoA = 0
    aveVtoV = 0
    try:
        for i in range(len(vtoaCounts)):
            aveAtoV += atovCounts[i]
            aveVtoA += vtoaCounts[i]
            aveAtoA += atoaCounts[i]
            aveVtoV += vtovCounts[i]
    except:
        print("i out of range")

    aveAtoV /= len(atoaCounts)
    aveVtoA /= len(atoaCounts)
    aveAtoA /= len(atoaCounts)
    aveVtoV /= len(atoaCounts)
    bpm = (1/(aveAtoA / 1000)) * 60
    print("A to V = ", aveAtoV)
    print("V to A = ", aveVtoA)
    print("A to A = ", aveAtoA)
    print("V to V = ", aveVtoV)
    print("BPM = ", bpm)


if __name__ == '__main__':
    main()
