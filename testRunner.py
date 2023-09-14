import csv


def main():
    file = open('test-0.csv', 'r+')

    # Define all of the timers
    atov = 0
    vtoa = 0
    atoa = 0

    atovCounts = []
    vtoaCounts = []
    atoaCounts = []

    # Define variables to count state
    waitingA = True
    waitingV = False

    csvReader = csv.DictReader(file)

    for col in csvReader:
        # Increment the timers
        atov += 1
        vtoa += 1
        atoa += 1
        if (waitingA):
            # If there is an atrium event
            if (int((col[' A']).strip()) == 1):
                waitingV = True
                atov = 0
                # First two second can be ignored
                if (float(col['Time']) > 2000):
                    vtoaCounts.append(vtoa)
                    atoaCounts.append(atoa)
                atoa = 0

        if (waitingV):
            if (int((col[' V']).strip()) == 1):
                waitingA = True
                vtoa = 0
                # First two second can be ignored
                if (float(col['Time']) > 2000):
                    atovCounts.append(atov)

    print("A to V counts", atovCounts)
    print("V to A counts", vtoaCounts)
    print("A to A counts", atoaCounts)

    aveAtoV = 0
    aveVtoA = 0
    aveAtoA = 0
    for i in range(len(atoaCounts)):
        aveAtoV += atovCounts[i]
        aveVtoA += vtoaCounts[i]
        aveAtoA += atoaCounts[i]

    aveAtoV /= i
    aveVtoA /= i
    aveAtoA /= i * 10
    print("A to V = ", aveAtoV)
    print("V to A = ", aveVtoA)
    print("BPM = ", aveAtoA)


if __name__ == '__main__':
    main()
