# Insertion

## Insertion at the beginning (INFO, LINK, START, AVAIL, ITEM)

**1.** If `AVAIL` = `NULL` Then write `OVERFLOW` and `exit`;
 
**2.** [Remove first node from `AVAIL`]
       
`NEW` = `AVAIL` and `AVAIL` = `LINK[AVAIL]`

**3.** Set `INFO[NEW]` = `ITEM`

**4.** Set `LINK[NEW]` = `START`

**5.** `START` = `NEW`

## Insertion after a given node (INFO, LINK, START, AVAIL, ITEM, LOC)

**1.** If `AVAIL` = `NULL` Then write `OVERFLOW` and `exit`;

**2.** [Remove first node from `AVAIL`]
       
`NEW` = `AVAIL` and `AVAIL` = `LINK[AVAIL]`

**3.** Set `INFO[NEW]` = `ITEM`

**4.** _**IF**_ `LOC` = `NULL`
       
`LINK[NEW]` = `START` and `START` = `NEW`

**5.** **_ELSE_** 

`LINK[NEW]` = `LINK[LOC]` and  `LINK[LOC]` = `NEW`

# Deletion

## Deletion after a given node(INFO, LINK, START, AVAIL, LOC, LOCP)

**1.** _**If**_ `LOCP` = `NULL`, then:

Set `START` = `LINK[START]`

_**ELSE**_

Set `LINK[LOCP]` = `LINK[LOC]`

**2.** `LINK[LOC]` = `AVAIL` and `AVAIL` = `LOC` 

[`LOC` now points to where the `TOP` of `AVAIL` list was pointing, and the `TOP` of `AVAIL` list now points to `LOC`]