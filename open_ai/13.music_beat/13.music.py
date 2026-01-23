def convert(noteLines: str) -> str:
    beats = []
    instruments = []
    for notes in noteLines.split("\n"):
        instrument, *_beats = notes.split(" ")
        beats.append(_beats)
        instruments.append(instrument)

    N = len(beats[0])
    K = len(instruments)

    beatsSoFar = 0
    hasBeat1 = 0
    namesSoFar = set()
    res = ""
    for i in range(N):
        # print(i) # 0,1,2,3
        namesAtThisColumn = set()
        for k in range(K):
            beat = int(beats[k][i])
            # 0|1 = 1, 1|1 = 1
            hasBeat1 = hasBeat1 | beat
            if beat == 1: #> 0:
                namesAtThisColumn.add(k)

        if hasBeat1:
            if beatsSoFar > 0:
                # collect the result
                ins = (
                    instruments[namesSoFar.pop()]
                    if len(namesSoFar) == 1
                    else f"<{','.join(instruments[x] for x in namesSoFar)}>"
                )
                res += f"{ins}{N//beatsSoFar}" + " "
            hasBeat1 = 0
            # has beat 1 so beat so far reset to 1
            beatsSoFar = 1
            namesSoFar = namesAtThisColumn

        else:
            # extend the beat
            beatsSoFar += 1
            namesSoFar = namesSoFar | namesAtThisColumn

    if beatsSoFar > 0:
        # collect the result
        ins = (
            instruments[namesSoFar.pop()]
            if len(namesSoFar) == 1
            else f"<{','.join(instruments[x] for x in namesSoFar)}>"
        )
        res += f"{ins}{N//beatsSoFar}"
    return res


# a 1 0 1 1
# b 0 0 1 0
# => a2 <a,b>4 a4

res = convert("a 1 0 1 1\nb 0 0 1 0")
assert res == "a2 <a,b>4 a4"
print(res)
