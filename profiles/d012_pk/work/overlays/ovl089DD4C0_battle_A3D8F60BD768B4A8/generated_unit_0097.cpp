#include "psprecomp/corpus_abi.hpp"
#include "ovl089DD4C0_battle_A3D8F60BD768B4A8_units.hpp"
#include <atomic>
#include <bit>
#include <cmath>
#include <cstdint>
#include <limits>

namespace psprecomp {
static const std::uint16_t kEntryIds_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097[1708] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
    33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
    97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128,
    129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160,
    161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192,
    193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224,
    225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256,
    257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288,
    289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320,
    321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352,
    353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384,
    385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416,
    417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448,
    449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480,
    481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512,
    513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544,
    545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576,
    577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607, 608,
    609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639, 640,
    641, 642, 643, 644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654, 655, 656, 657, 658, 659, 660, 661, 662, 663, 664, 665, 666, 667, 668, 669, 670, 671, 672,
    673, 674, 675, 676, 677, 678, 679, 680, 681, 682, 683, 684, 685, 686, 687, 688, 689, 690, 691, 692, 693, 694, 695, 696, 697, 698, 699, 700, 701, 702, 703, 704,
    705, 706, 707, 708, 709, 710, 711, 712, 713, 714, 715, 716, 717, 718, 719, 720, 721, 722, 723, 724, 725, 726, 727, 728, 729, 730, 731, 732, 733, 734, 735, 736,
    737, 738, 739, 740, 741, 742, 743, 744, 745, 746, 747, 748, 749, 750, 751, 752, 753, 754, 755, 756, 757, 758, 759, 760, 761, 762, 763, 764, 765, 766, 767, 768,
    769, 770, 771, 772, 773, 774, 775, 776, 777, 778, 779, 780, 781, 782, 783, 784, 785, 786, 787, 788, 789, 790, 791, 792, 793, 794, 795, 796, 797, 798, 799, 800,
    801, 802, 803, 804, 805, 806, 807, 808, 809, 810, 811, 812, 813, 814, 815, 816, 817, 818, 819, 820, 821, 822, 823, 824, 825, 826, 827, 828, 829, 830, 831, 832,
    833, 834, 835, 836, 837, 838, 839, 840, 841, 842, 843, 844, 845, 846, 847, 848, 849, 850, 851, 852, 853, 854, 855, 856, 857, 858, 859, 860, 861, 862, 863, 864,
    865, 866, 867, 868, 869, 870, 871, 872, 873, 874, 875, 876, 877, 878, 879, 880, 881, 882, 883, 884, 885, 886, 887, 888, 889, 890, 891, 892, 893, 894, 895, 896,
    897, 898, 899, 900, 901, 902, 903, 904, 905, 906, 907, 908, 909, 910, 911, 912, 913, 914, 915, 916, 917, 918, 919, 920, 921, 922, 923, 924, 925, 926, 927, 928,
    929, 930, 931, 932, 933, 934, 935, 936, 937, 938, 939, 940, 941, 942, 943, 944, 945, 946, 947, 948, 949, 950, 951, 952, 953, 954, 955, 956, 957, 958, 959, 960,
    961, 962, 963, 964, 965, 966, 967, 968, 969, 970, 971, 972, 973, 974, 975, 976, 977, 978, 979, 980, 981, 982, 983, 984, 985, 986, 987, 988, 989, 990, 991, 992,
    993, 994, 995, 996, 997, 998, 999, 1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024,
    1025, 1026, 1027, 1028, 1029, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1039, 1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052, 1053, 1054, 1055, 1056,
    1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065, 1066, 1067, 1068, 1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088,
    1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110, 1111, 1112, 1113, 1114, 1115, 1116, 1117, 1118, 1119, 1120,
    1121, 1122, 1123, 1124, 1125, 1126, 1127, 1128, 1129, 1130, 1131, 1132, 1133, 1134, 1135, 1136, 1137, 1138, 1139, 1140, 1141, 1142, 1143, 1144, 1145, 1146, 1147, 1148, 1149, 1150, 1151, 1152,
    1153, 1154, 1155, 1156, 1157, 1158, 1159, 1160, 1161, 1162, 1163, 1164, 1165, 1166, 1167, 1168, 1169, 1170, 1171, 1172, 1173, 1174, 1175, 1176, 1177, 1178, 1179, 1180, 1181, 1182, 1183, 1184,
    1185, 1186, 1187, 1188, 1189, 1190, 1191, 1192, 1193, 1194, 1195, 1196, 1197, 1198, 1199, 1200, 1201, 1202, 1203, 1204, 1205, 1206, 1207, 1208, 1209, 1210, 1211, 1212, 1213, 1214, 1215, 1216,
    1217, 1218, 1219, 1220, 1221, 1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, 1232, 1233, 1234, 1235, 1236, 1237, 1238, 1239, 1240, 1241, 1242, 1243, 1244, 1245, 1246, 1247, 1248,
    1249, 1250, 1251, 1252, 1253, 1254, 1255, 1256, 1257, 1258, 1259, 1260, 1261, 1262, 1263, 1264, 1265, 1266, 1267, 1268, 1269, 1270, 1271, 1272, 1273, 1274, 1275, 1276, 1277, 1278, 1279, 1280,
    1281, 1282, 1283, 1284, 1285, 1286, 1287, 1288, 1289, 1290, 1291, 1292, 1293, 1294, 1295, 1296, 1297, 1298, 1299, 1300, 1301, 1302, 1303, 1304, 1305, 1306, 1307, 1308, 1309, 1310, 1311, 1312,
    1313, 1314, 1315, 1316, 1317, 1318, 1319, 1320, 1321, 1322, 1323, 1324, 1325, 1326, 1327, 1328, 1329, 1330, 1331, 1332, 1333, 1334, 1335, 1336, 1337, 1338, 1339, 1340, 1341, 1342, 1343, 1344,
    1345, 1346, 1347, 1348, 1349, 1350, 1351, 1352, 1353, 1354, 1355, 1356, 1357, 1358, 1359, 1360, 1361, 1362, 1363, 1364, 1365, 1366, 1367, 1368, 1369, 1370, 1371, 1372, 1373, 1374, 1375, 1376,
    1377, 1378, 1379, 1380, 1381, 1382, 1383, 1384, 1385, 1386, 1387, 1388, 1389, 1390, 1391, 1392, 1393, 1394, 1395, 1396, 1397, 1398, 1399, 1400, 1401, 1402, 1403, 1404, 1405, 1406, 1407, 1408,
    1409, 1410, 1411, 1412, 1413, 1414, 1415, 1416, 1417, 1418, 1419, 1420, 1421, 1422, 1423, 1424, 1425, 1426, 1427, 1428, 1429, 1430, 1431, 1432, 1433, 1434, 1435, 1436, 1437, 1438, 1439, 1440,
    1441, 1442, 1443, 1444, 1445, 1446, 1447, 1448, 1449, 1450, 1451, 1452, 1453, 1454, 1455, 1456, 1457, 1458, 1459, 1460, 1461, 1462, 1463, 1464, 1465, 1466, 1467, 1468, 1469, 1470, 1471, 1472,
    1473, 1474, 1475, 1476, 1477, 1478, 1479, 1480, 1481, 1482, 1483, 1484, 1485, 1486, 1487, 1488, 1489, 1490, 1491, 1492, 1493, 1494, 1495, 1496, 1497, 1498, 1499, 1500, 1501, 1502, 1503, 1504,
    1505, 1506, 1507, 1508, 1509, 1510, 1511, 1512, 1513, 1514, 1515, 1516, 1517, 1518, 1519, 1520, 1521, 1522, 1523, 1524, 1525, 1526, 1527, 1528, 1529, 1530, 1531, 1532, 1533, 1534, 1535, 1536,
    1537, 1538, 1539, 1540, 1541, 1542, 1543, 1544, 1545, 1546, 1547, 1548, 1549, 1550, 1551, 1552, 1553, 1554, 1555, 1556, 1557, 1558, 1559, 1560, 1561, 1562, 1563, 1564, 1565, 1566, 1567, 1568,
    1569, 1570, 1571, 1572, 1573, 1574, 1575, 1576, 1577, 1578, 1579, 1580, 1581, 1582, 1583, 1584, 1585, 1586, 1587, 1588, 1589, 1590, 1591, 1592, 1593, 1594, 1595, 1596, 1597, 1598, 1599, 1600,
    1601, 1602, 1603, 1604, 1605, 1606, 1607, 1608, 1609, 1610, 1611, 1612, 1613, 1614, 1615, 1616, 1617, 1618, 1619, 1620, 1621, 1622, 1623, 1624, 1625, 1626, 1627, 1628, 1629, 1630, 1631, 1632,
    1633, 1634, 1635, 1636, 1637, 1638, 1639, 1640, 1641, 1642, 1643, 1644, 1645, 1646, 1647, 1648, 1649, 1650, 1651, 1652, 1653, 1654, 1655, 1656, 1657, 1658, 1659, 1660, 1661, 1662, 1663, 1664,
    1665, 1666, 1667, 1668, 1669, 1670, 1671, 1672, 1673, 1674, 1675, 1676, 1677, 1678, 1679, 1680, 1681, 1682, 1683, 1684, 1685, 1686, 1687, 1688, 1689, 1690, 1691, 1692, 1693, 1694, 1695, 1696,
    1697, 1698, 1699, 1700, 1701, 1702, 1703, 1704, 1705, 1706, 1707, 1708,
};
void ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097_entry(CorpusRuntime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B614C0u;
        entry_id = (entry_delta < 6832u && (entry_delta & 3u) == 0u) ? kEntryIds_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B614C0;
    case 2u: goto L_08B614C4;
    case 3u: goto L_08B614C8;
    case 4u: goto L_08B614CC;
    case 5u: goto L_08B614D0;
    case 6u: goto L_08B614D4;
    case 7u: goto L_08B614D8;
    case 8u: goto L_08B614DC;
    case 9u: goto L_08B614E0;
    case 10u: goto L_08B614E4;
    case 11u: goto L_08B614E8;
    case 12u: goto L_08B614EC;
    case 13u: goto L_08B614F0;
    case 14u: goto L_08B614F4;
    case 15u: goto L_08B614F8;
    case 16u: goto L_08B614FC;
    case 17u: goto L_08B61500;
    case 18u: goto L_08B61504;
    case 19u: goto L_08B61508;
    case 20u: goto L_08B6150C;
    case 21u: goto L_08B61510;
    case 22u: goto L_08B61514;
    case 23u: goto L_08B61518;
    case 24u: goto L_08B6151C;
    case 25u: goto L_08B61520;
    case 26u: goto L_08B61524;
    case 27u: goto L_08B61528;
    case 28u: goto L_08B6152C;
    case 29u: goto L_08B61530;
    case 30u: goto L_08B61534;
    case 31u: goto L_08B61538;
    case 32u: goto L_08B6153C;
    case 33u: goto L_08B61540;
    case 34u: goto L_08B61544;
    case 35u: goto L_08B61548;
    case 36u: goto L_08B6154C;
    case 37u: goto L_08B61550;
    case 38u: goto L_08B61554;
    case 39u: goto L_08B61558;
    case 40u: goto L_08B6155C;
    case 41u: goto L_08B61560;
    case 42u: goto L_08B61564;
    case 43u: goto L_08B61568;
    case 44u: goto L_08B6156C;
    case 45u: goto L_08B61570;
    case 46u: goto L_08B61574;
    case 47u: goto L_08B61578;
    case 48u: goto L_08B6157C;
    case 49u: goto L_08B61580;
    case 50u: goto L_08B61584;
    case 51u: goto L_08B61588;
    case 52u: goto L_08B6158C;
    case 53u: goto L_08B61590;
    case 54u: goto L_08B61594;
    case 55u: goto L_08B61598;
    case 56u: goto L_08B6159C;
    case 57u: goto L_08B615A0;
    case 58u: goto L_08B615A4;
    case 59u: goto L_08B615A8;
    case 60u: goto L_08B615AC;
    case 61u: goto L_08B615B0;
    case 62u: goto L_08B615B4;
    case 63u: goto L_08B615B8;
    case 64u: goto L_08B615BC;
    case 65u: goto L_08B615C0;
    case 66u: goto L_08B615C4;
    case 67u: goto L_08B615C8;
    case 68u: goto L_08B615CC;
    case 69u: goto L_08B615D0;
    case 70u: goto L_08B615D4;
    case 71u: goto L_08B615D8;
    case 72u: goto L_08B615DC;
    case 73u: goto L_08B615E0;
    case 74u: goto L_08B615E4;
    case 75u: goto L_08B615E8;
    case 76u: goto L_08B615EC;
    case 77u: goto L_08B615F0;
    case 78u: goto L_08B615F4;
    case 79u: goto L_08B615F8;
    case 80u: goto L_08B615FC;
    case 81u: goto L_08B61600;
    case 82u: goto L_08B61604;
    case 83u: goto L_08B61608;
    case 84u: goto L_08B6160C;
    case 85u: goto L_08B61610;
    case 86u: goto L_08B61614;
    case 87u: goto L_08B61618;
    case 88u: goto L_08B6161C;
    case 89u: goto L_08B61620;
    case 90u: goto L_08B61624;
    case 91u: goto L_08B61628;
    case 92u: goto L_08B6162C;
    case 93u: goto L_08B61630;
    case 94u: goto L_08B61634;
    case 95u: goto L_08B61638;
    case 96u: goto L_08B6163C;
    case 97u: goto L_08B61640;
    case 98u: goto L_08B61644;
    case 99u: goto L_08B61648;
    case 100u: goto L_08B6164C;
    case 101u: goto L_08B61650;
    case 102u: goto L_08B61654;
    case 103u: goto L_08B61658;
    case 104u: goto L_08B6165C;
    case 105u: goto L_08B61660;
    case 106u: goto L_08B61664;
    case 107u: goto L_08B61668;
    case 108u: goto L_08B6166C;
    case 109u: goto L_08B61670;
    case 110u: goto L_08B61674;
    case 111u: goto L_08B61678;
    case 112u: goto L_08B6167C;
    case 113u: goto L_08B61680;
    case 114u: goto L_08B61684;
    case 115u: goto L_08B61688;
    case 116u: goto L_08B6168C;
    case 117u: goto L_08B61690;
    case 118u: goto L_08B61694;
    case 119u: goto L_08B61698;
    case 120u: goto L_08B6169C;
    case 121u: goto L_08B616A0;
    case 122u: goto L_08B616A4;
    case 123u: goto L_08B616A8;
    case 124u: goto L_08B616AC;
    case 125u: goto L_08B616B0;
    case 126u: goto L_08B616B4;
    case 127u: goto L_08B616B8;
    case 128u: goto L_08B616BC;
    case 129u: goto L_08B616C0;
    case 130u: goto L_08B616C4;
    case 131u: goto L_08B616C8;
    case 132u: goto L_08B616CC;
    case 133u: goto L_08B616D0;
    case 134u: goto L_08B616D4;
    case 135u: goto L_08B616D8;
    case 136u: goto L_08B616DC;
    case 137u: goto L_08B616E0;
    case 138u: goto L_08B616E4;
    case 139u: goto L_08B616E8;
    case 140u: goto L_08B616EC;
    case 141u: goto L_08B616F0;
    case 142u: goto L_08B616F4;
    case 143u: goto L_08B616F8;
    case 144u: goto L_08B616FC;
    case 145u: goto L_08B61700;
    case 146u: goto L_08B61704;
    case 147u: goto L_08B61708;
    case 148u: goto L_08B6170C;
    case 149u: goto L_08B61710;
    case 150u: goto L_08B61714;
    case 151u: goto L_08B61718;
    case 152u: goto L_08B6171C;
    case 153u: goto L_08B61720;
    case 154u: goto L_08B61724;
    case 155u: goto L_08B61728;
    case 156u: goto L_08B6172C;
    case 157u: goto L_08B61730;
    case 158u: goto L_08B61734;
    case 159u: goto L_08B61738;
    case 160u: goto L_08B6173C;
    case 161u: goto L_08B61740;
    case 162u: goto L_08B61744;
    case 163u: goto L_08B61748;
    case 164u: goto L_08B6174C;
    case 165u: goto L_08B61750;
    case 166u: goto L_08B61754;
    case 167u: goto L_08B61758;
    case 168u: goto L_08B6175C;
    case 169u: goto L_08B61760;
    case 170u: goto L_08B61764;
    case 171u: goto L_08B61768;
    case 172u: goto L_08B6176C;
    case 173u: goto L_08B61770;
    case 174u: goto L_08B61774;
    case 175u: goto L_08B61778;
    case 176u: goto L_08B6177C;
    case 177u: goto L_08B61780;
    case 178u: goto L_08B61784;
    case 179u: goto L_08B61788;
    case 180u: goto L_08B6178C;
    case 181u: goto L_08B61790;
    case 182u: goto L_08B61794;
    case 183u: goto L_08B61798;
    case 184u: goto L_08B6179C;
    case 185u: goto L_08B617A0;
    case 186u: goto L_08B617A4;
    case 187u: goto L_08B617A8;
    case 188u: goto L_08B617AC;
    case 189u: goto L_08B617B0;
    case 190u: goto L_08B617B4;
    case 191u: goto L_08B617B8;
    case 192u: goto L_08B617BC;
    case 193u: goto L_08B617C0;
    case 194u: goto L_08B617C4;
    case 195u: goto L_08B617C8;
    case 196u: goto L_08B617CC;
    case 197u: goto L_08B617D0;
    case 198u: goto L_08B617D4;
    case 199u: goto L_08B617D8;
    case 200u: goto L_08B617DC;
    case 201u: goto L_08B617E0;
    case 202u: goto L_08B617E4;
    case 203u: goto L_08B617E8;
    case 204u: goto L_08B617EC;
    case 205u: goto L_08B617F0;
    case 206u: goto L_08B617F4;
    case 207u: goto L_08B617F8;
    case 208u: goto L_08B617FC;
    case 209u: goto L_08B61800;
    case 210u: goto L_08B61804;
    case 211u: goto L_08B61808;
    case 212u: goto L_08B6180C;
    case 213u: goto L_08B61810;
    case 214u: goto L_08B61814;
    case 215u: goto L_08B61818;
    case 216u: goto L_08B6181C;
    case 217u: goto L_08B61820;
    case 218u: goto L_08B61824;
    case 219u: goto L_08B61828;
    case 220u: goto L_08B6182C;
    case 221u: goto L_08B61830;
    case 222u: goto L_08B61834;
    case 223u: goto L_08B61838;
    case 224u: goto L_08B6183C;
    case 225u: goto L_08B61840;
    case 226u: goto L_08B61844;
    case 227u: goto L_08B61848;
    case 228u: goto L_08B6184C;
    case 229u: goto L_08B61850;
    case 230u: goto L_08B61854;
    case 231u: goto L_08B61858;
    case 232u: goto L_08B6185C;
    case 233u: goto L_08B61860;
    case 234u: goto L_08B61864;
    case 235u: goto L_08B61868;
    case 236u: goto L_08B6186C;
    case 237u: goto L_08B61870;
    case 238u: goto L_08B61874;
    case 239u: goto L_08B61878;
    case 240u: goto L_08B6187C;
    case 241u: goto L_08B61880;
    case 242u: goto L_08B61884;
    case 243u: goto L_08B61888;
    case 244u: goto L_08B6188C;
    case 245u: goto L_08B61890;
    case 246u: goto L_08B61894;
    case 247u: goto L_08B61898;
    case 248u: goto L_08B6189C;
    case 249u: goto L_08B618A0;
    case 250u: goto L_08B618A4;
    case 251u: goto L_08B618A8;
    case 252u: goto L_08B618AC;
    case 253u: goto L_08B618B0;
    case 254u: goto L_08B618B4;
    case 255u: goto L_08B618B8;
    case 256u: goto L_08B618BC;
    case 257u: goto L_08B618C0;
    case 258u: goto L_08B618C4;
    case 259u: goto L_08B618C8;
    case 260u: goto L_08B618CC;
    case 261u: goto L_08B618D0;
    case 262u: goto L_08B618D4;
    case 263u: goto L_08B618D8;
    case 264u: goto L_08B618DC;
    case 265u: goto L_08B618E0;
    case 266u: goto L_08B618E4;
    case 267u: goto L_08B618E8;
    case 268u: goto L_08B618EC;
    case 269u: goto L_08B618F0;
    case 270u: goto L_08B618F4;
    case 271u: goto L_08B618F8;
    case 272u: goto L_08B618FC;
    case 273u: goto L_08B61900;
    case 274u: goto L_08B61904;
    case 275u: goto L_08B61908;
    case 276u: goto L_08B6190C;
    case 277u: goto L_08B61910;
    case 278u: goto L_08B61914;
    case 279u: goto L_08B61918;
    case 280u: goto L_08B6191C;
    case 281u: goto L_08B61920;
    case 282u: goto L_08B61924;
    case 283u: goto L_08B61928;
    case 284u: goto L_08B6192C;
    case 285u: goto L_08B61930;
    case 286u: goto L_08B61934;
    case 287u: goto L_08B61938;
    case 288u: goto L_08B6193C;
    case 289u: goto L_08B61940;
    case 290u: goto L_08B61944;
    case 291u: goto L_08B61948;
    case 292u: goto L_08B6194C;
    case 293u: goto L_08B61950;
    case 294u: goto L_08B61954;
    case 295u: goto L_08B61958;
    case 296u: goto L_08B6195C;
    case 297u: goto L_08B61960;
    case 298u: goto L_08B61964;
    case 299u: goto L_08B61968;
    case 300u: goto L_08B6196C;
    case 301u: goto L_08B61970;
    case 302u: goto L_08B61974;
    case 303u: goto L_08B61978;
    case 304u: goto L_08B6197C;
    case 305u: goto L_08B61980;
    case 306u: goto L_08B61984;
    case 307u: goto L_08B61988;
    case 308u: goto L_08B6198C;
    case 309u: goto L_08B61990;
    case 310u: goto L_08B61994;
    case 311u: goto L_08B61998;
    case 312u: goto L_08B6199C;
    case 313u: goto L_08B619A0;
    case 314u: goto L_08B619A4;
    case 315u: goto L_08B619A8;
    case 316u: goto L_08B619AC;
    case 317u: goto L_08B619B0;
    case 318u: goto L_08B619B4;
    case 319u: goto L_08B619B8;
    case 320u: goto L_08B619BC;
    case 321u: goto L_08B619C0;
    case 322u: goto L_08B619C4;
    case 323u: goto L_08B619C8;
    case 324u: goto L_08B619CC;
    case 325u: goto L_08B619D0;
    case 326u: goto L_08B619D4;
    case 327u: goto L_08B619D8;
    case 328u: goto L_08B619DC;
    case 329u: goto L_08B619E0;
    case 330u: goto L_08B619E4;
    case 331u: goto L_08B619E8;
    case 332u: goto L_08B619EC;
    case 333u: goto L_08B619F0;
    case 334u: goto L_08B619F4;
    case 335u: goto L_08B619F8;
    case 336u: goto L_08B619FC;
    case 337u: goto L_08B61A00;
    case 338u: goto L_08B61A04;
    case 339u: goto L_08B61A08;
    case 340u: goto L_08B61A0C;
    case 341u: goto L_08B61A10;
    case 342u: goto L_08B61A14;
    case 343u: goto L_08B61A18;
    case 344u: goto L_08B61A1C;
    case 345u: goto L_08B61A20;
    case 346u: goto L_08B61A24;
    case 347u: goto L_08B61A28;
    case 348u: goto L_08B61A2C;
    case 349u: goto L_08B61A30;
    case 350u: goto L_08B61A34;
    case 351u: goto L_08B61A38;
    case 352u: goto L_08B61A3C;
    case 353u: goto L_08B61A40;
    case 354u: goto L_08B61A44;
    case 355u: goto L_08B61A48;
    case 356u: goto L_08B61A4C;
    case 357u: goto L_08B61A50;
    case 358u: goto L_08B61A54;
    case 359u: goto L_08B61A58;
    case 360u: goto L_08B61A5C;
    case 361u: goto L_08B61A60;
    case 362u: goto L_08B61A64;
    case 363u: goto L_08B61A68;
    case 364u: goto L_08B61A6C;
    case 365u: goto L_08B61A70;
    case 366u: goto L_08B61A74;
    case 367u: goto L_08B61A78;
    case 368u: goto L_08B61A7C;
    case 369u: goto L_08B61A80;
    case 370u: goto L_08B61A84;
    case 371u: goto L_08B61A88;
    case 372u: goto L_08B61A8C;
    case 373u: goto L_08B61A90;
    case 374u: goto L_08B61A94;
    case 375u: goto L_08B61A98;
    case 376u: goto L_08B61A9C;
    case 377u: goto L_08B61AA0;
    case 378u: goto L_08B61AA4;
    case 379u: goto L_08B61AA8;
    case 380u: goto L_08B61AAC;
    case 381u: goto L_08B61AB0;
    case 382u: goto L_08B61AB4;
    case 383u: goto L_08B61AB8;
    case 384u: goto L_08B61ABC;
    case 385u: goto L_08B61AC0;
    case 386u: goto L_08B61AC4;
    case 387u: goto L_08B61AC8;
    case 388u: goto L_08B61ACC;
    case 389u: goto L_08B61AD0;
    case 390u: goto L_08B61AD4;
    case 391u: goto L_08B61AD8;
    case 392u: goto L_08B61ADC;
    case 393u: goto L_08B61AE0;
    case 394u: goto L_08B61AE4;
    case 395u: goto L_08B61AE8;
    case 396u: goto L_08B61AEC;
    case 397u: goto L_08B61AF0;
    case 398u: goto L_08B61AF4;
    case 399u: goto L_08B61AF8;
    case 400u: goto L_08B61AFC;
    case 401u: goto L_08B61B00;
    case 402u: goto L_08B61B04;
    case 403u: goto L_08B61B08;
    case 404u: goto L_08B61B0C;
    case 405u: goto L_08B61B10;
    case 406u: goto L_08B61B14;
    case 407u: goto L_08B61B18;
    case 408u: goto L_08B61B1C;
    case 409u: goto L_08B61B20;
    case 410u: goto L_08B61B24;
    case 411u: goto L_08B61B28;
    case 412u: goto L_08B61B2C;
    case 413u: goto L_08B61B30;
    case 414u: goto L_08B61B34;
    case 415u: goto L_08B61B38;
    case 416u: goto L_08B61B3C;
    case 417u: goto L_08B61B40;
    case 418u: goto L_08B61B44;
    case 419u: goto L_08B61B48;
    case 420u: goto L_08B61B4C;
    case 421u: goto L_08B61B50;
    case 422u: goto L_08B61B54;
    case 423u: goto L_08B61B58;
    case 424u: goto L_08B61B5C;
    case 425u: goto L_08B61B60;
    case 426u: goto L_08B61B64;
    case 427u: goto L_08B61B68;
    case 428u: goto L_08B61B6C;
    case 429u: goto L_08B61B70;
    case 430u: goto L_08B61B74;
    case 431u: goto L_08B61B78;
    case 432u: goto L_08B61B7C;
    case 433u: goto L_08B61B80;
    case 434u: goto L_08B61B84;
    case 435u: goto L_08B61B88;
    case 436u: goto L_08B61B8C;
    case 437u: goto L_08B61B90;
    case 438u: goto L_08B61B94;
    case 439u: goto L_08B61B98;
    case 440u: goto L_08B61B9C;
    case 441u: goto L_08B61BA0;
    case 442u: goto L_08B61BA4;
    case 443u: goto L_08B61BA8;
    case 444u: goto L_08B61BAC;
    case 445u: goto L_08B61BB0;
    case 446u: goto L_08B61BB4;
    case 447u: goto L_08B61BB8;
    case 448u: goto L_08B61BBC;
    case 449u: goto L_08B61BC0;
    case 450u: goto L_08B61BC4;
    case 451u: goto L_08B61BC8;
    case 452u: goto L_08B61BCC;
    case 453u: goto L_08B61BD0;
    case 454u: goto L_08B61BD4;
    case 455u: goto L_08B61BD8;
    case 456u: goto L_08B61BDC;
    case 457u: goto L_08B61BE0;
    case 458u: goto L_08B61BE4;
    case 459u: goto L_08B61BE8;
    case 460u: goto L_08B61BEC;
    case 461u: goto L_08B61BF0;
    case 462u: goto L_08B61BF4;
    case 463u: goto L_08B61BF8;
    case 464u: goto L_08B61BFC;
    case 465u: goto L_08B61C00;
    case 466u: goto L_08B61C04;
    case 467u: goto L_08B61C08;
    case 468u: goto L_08B61C0C;
    case 469u: goto L_08B61C10;
    case 470u: goto L_08B61C14;
    case 471u: goto L_08B61C18;
    case 472u: goto L_08B61C1C;
    case 473u: goto L_08B61C20;
    case 474u: goto L_08B61C24;
    case 475u: goto L_08B61C28;
    case 476u: goto L_08B61C2C;
    case 477u: goto L_08B61C30;
    case 478u: goto L_08B61C34;
    case 479u: goto L_08B61C38;
    case 480u: goto L_08B61C3C;
    case 481u: goto L_08B61C40;
    case 482u: goto L_08B61C44;
    case 483u: goto L_08B61C48;
    case 484u: goto L_08B61C4C;
    case 485u: goto L_08B61C50;
    case 486u: goto L_08B61C54;
    case 487u: goto L_08B61C58;
    case 488u: goto L_08B61C5C;
    case 489u: goto L_08B61C60;
    case 490u: goto L_08B61C64;
    case 491u: goto L_08B61C68;
    case 492u: goto L_08B61C6C;
    case 493u: goto L_08B61C70;
    case 494u: goto L_08B61C74;
    case 495u: goto L_08B61C78;
    case 496u: goto L_08B61C7C;
    case 497u: goto L_08B61C80;
    case 498u: goto L_08B61C84;
    case 499u: goto L_08B61C88;
    case 500u: goto L_08B61C8C;
    case 501u: goto L_08B61C90;
    case 502u: goto L_08B61C94;
    case 503u: goto L_08B61C98;
    case 504u: goto L_08B61C9C;
    case 505u: goto L_08B61CA0;
    case 506u: goto L_08B61CA4;
    case 507u: goto L_08B61CA8;
    case 508u: goto L_08B61CAC;
    case 509u: goto L_08B61CB0;
    case 510u: goto L_08B61CB4;
    case 511u: goto L_08B61CB8;
    case 512u: goto L_08B61CBC;
    case 513u: goto L_08B61CC0;
    case 514u: goto L_08B61CC4;
    case 515u: goto L_08B61CC8;
    case 516u: goto L_08B61CCC;
    case 517u: goto L_08B61CD0;
    case 518u: goto L_08B61CD4;
    case 519u: goto L_08B61CD8;
    case 520u: goto L_08B61CDC;
    case 521u: goto L_08B61CE0;
    case 522u: goto L_08B61CE4;
    case 523u: goto L_08B61CE8;
    case 524u: goto L_08B61CEC;
    case 525u: goto L_08B61CF0;
    case 526u: goto L_08B61CF4;
    case 527u: goto L_08B61CF8;
    case 528u: goto L_08B61CFC;
    case 529u: goto L_08B61D00;
    case 530u: goto L_08B61D04;
    case 531u: goto L_08B61D08;
    case 532u: goto L_08B61D0C;
    case 533u: goto L_08B61D10;
    case 534u: goto L_08B61D14;
    case 535u: goto L_08B61D18;
    case 536u: goto L_08B61D1C;
    case 537u: goto L_08B61D20;
    case 538u: goto L_08B61D24;
    case 539u: goto L_08B61D28;
    case 540u: goto L_08B61D2C;
    case 541u: goto L_08B61D30;
    case 542u: goto L_08B61D34;
    case 543u: goto L_08B61D38;
    case 544u: goto L_08B61D3C;
    case 545u: goto L_08B61D40;
    case 546u: goto L_08B61D44;
    case 547u: goto L_08B61D48;
    case 548u: goto L_08B61D4C;
    case 549u: goto L_08B61D50;
    case 550u: goto L_08B61D54;
    case 551u: goto L_08B61D58;
    case 552u: goto L_08B61D5C;
    case 553u: goto L_08B61D60;
    case 554u: goto L_08B61D64;
    case 555u: goto L_08B61D68;
    case 556u: goto L_08B61D6C;
    case 557u: goto L_08B61D70;
    case 558u: goto L_08B61D74;
    case 559u: goto L_08B61D78;
    case 560u: goto L_08B61D7C;
    case 561u: goto L_08B61D80;
    case 562u: goto L_08B61D84;
    case 563u: goto L_08B61D88;
    case 564u: goto L_08B61D8C;
    case 565u: goto L_08B61D90;
    case 566u: goto L_08B61D94;
    case 567u: goto L_08B61D98;
    case 568u: goto L_08B61D9C;
    case 569u: goto L_08B61DA0;
    case 570u: goto L_08B61DA4;
    case 571u: goto L_08B61DA8;
    case 572u: goto L_08B61DAC;
    case 573u: goto L_08B61DB0;
    case 574u: goto L_08B61DB4;
    case 575u: goto L_08B61DB8;
    case 576u: goto L_08B61DBC;
    case 577u: goto L_08B61DC0;
    case 578u: goto L_08B61DC4;
    case 579u: goto L_08B61DC8;
    case 580u: goto L_08B61DCC;
    case 581u: goto L_08B61DD0;
    case 582u: goto L_08B61DD4;
    case 583u: goto L_08B61DD8;
    case 584u: goto L_08B61DDC;
    case 585u: goto L_08B61DE0;
    case 586u: goto L_08B61DE4;
    case 587u: goto L_08B61DE8;
    case 588u: goto L_08B61DEC;
    case 589u: goto L_08B61DF0;
    case 590u: goto L_08B61DF4;
    case 591u: goto L_08B61DF8;
    case 592u: goto L_08B61DFC;
    case 593u: goto L_08B61E00;
    case 594u: goto L_08B61E04;
    case 595u: goto L_08B61E08;
    case 596u: goto L_08B61E0C;
    case 597u: goto L_08B61E10;
    case 598u: goto L_08B61E14;
    case 599u: goto L_08B61E18;
    case 600u: goto L_08B61E1C;
    case 601u: goto L_08B61E20;
    case 602u: goto L_08B61E24;
    case 603u: goto L_08B61E28;
    case 604u: goto L_08B61E2C;
    case 605u: goto L_08B61E30;
    case 606u: goto L_08B61E34;
    case 607u: goto L_08B61E38;
    case 608u: goto L_08B61E3C;
    case 609u: goto L_08B61E40;
    case 610u: goto L_08B61E44;
    case 611u: goto L_08B61E48;
    case 612u: goto L_08B61E4C;
    case 613u: goto L_08B61E50;
    case 614u: goto L_08B61E54;
    case 615u: goto L_08B61E58;
    case 616u: goto L_08B61E5C;
    case 617u: goto L_08B61E60;
    case 618u: goto L_08B61E64;
    case 619u: goto L_08B61E68;
    case 620u: goto L_08B61E6C;
    case 621u: goto L_08B61E70;
    case 622u: goto L_08B61E74;
    case 623u: goto L_08B61E78;
    case 624u: goto L_08B61E7C;
    case 625u: goto L_08B61E80;
    case 626u: goto L_08B61E84;
    case 627u: goto L_08B61E88;
    case 628u: goto L_08B61E8C;
    case 629u: goto L_08B61E90;
    case 630u: goto L_08B61E94;
    case 631u: goto L_08B61E98;
    case 632u: goto L_08B61E9C;
    case 633u: goto L_08B61EA0;
    case 634u: goto L_08B61EA4;
    case 635u: goto L_08B61EA8;
    case 636u: goto L_08B61EAC;
    case 637u: goto L_08B61EB0;
    case 638u: goto L_08B61EB4;
    case 639u: goto L_08B61EB8;
    case 640u: goto L_08B61EBC;
    case 641u: goto L_08B61EC0;
    case 642u: goto L_08B61EC4;
    case 643u: goto L_08B61EC8;
    case 644u: goto L_08B61ECC;
    case 645u: goto L_08B61ED0;
    case 646u: goto L_08B61ED4;
    case 647u: goto L_08B61ED8;
    case 648u: goto L_08B61EDC;
    case 649u: goto L_08B61EE0;
    case 650u: goto L_08B61EE4;
    case 651u: goto L_08B61EE8;
    case 652u: goto L_08B61EEC;
    case 653u: goto L_08B61EF0;
    case 654u: goto L_08B61EF4;
    case 655u: goto L_08B61EF8;
    case 656u: goto L_08B61EFC;
    case 657u: goto L_08B61F00;
    case 658u: goto L_08B61F04;
    case 659u: goto L_08B61F08;
    case 660u: goto L_08B61F0C;
    case 661u: goto L_08B61F10;
    case 662u: goto L_08B61F14;
    case 663u: goto L_08B61F18;
    case 664u: goto L_08B61F1C;
    case 665u: goto L_08B61F20;
    case 666u: goto L_08B61F24;
    case 667u: goto L_08B61F28;
    case 668u: goto L_08B61F2C;
    case 669u: goto L_08B61F30;
    case 670u: goto L_08B61F34;
    case 671u: goto L_08B61F38;
    case 672u: goto L_08B61F3C;
    case 673u: goto L_08B61F40;
    case 674u: goto L_08B61F44;
    case 675u: goto L_08B61F48;
    case 676u: goto L_08B61F4C;
    case 677u: goto L_08B61F50;
    case 678u: goto L_08B61F54;
    case 679u: goto L_08B61F58;
    case 680u: goto L_08B61F5C;
    case 681u: goto L_08B61F60;
    case 682u: goto L_08B61F64;
    case 683u: goto L_08B61F68;
    case 684u: goto L_08B61F6C;
    case 685u: goto L_08B61F70;
    case 686u: goto L_08B61F74;
    case 687u: goto L_08B61F78;
    case 688u: goto L_08B61F7C;
    case 689u: goto L_08B61F80;
    case 690u: goto L_08B61F84;
    case 691u: goto L_08B61F88;
    case 692u: goto L_08B61F8C;
    case 693u: goto L_08B61F90;
    case 694u: goto L_08B61F94;
    case 695u: goto L_08B61F98;
    case 696u: goto L_08B61F9C;
    case 697u: goto L_08B61FA0;
    case 698u: goto L_08B61FA4;
    case 699u: goto L_08B61FA8;
    case 700u: goto L_08B61FAC;
    case 701u: goto L_08B61FB0;
    case 702u: goto L_08B61FB4;
    case 703u: goto L_08B61FB8;
    case 704u: goto L_08B61FBC;
    case 705u: goto L_08B61FC0;
    case 706u: goto L_08B61FC4;
    case 707u: goto L_08B61FC8;
    case 708u: goto L_08B61FCC;
    case 709u: goto L_08B61FD0;
    case 710u: goto L_08B61FD4;
    case 711u: goto L_08B61FD8;
    case 712u: goto L_08B61FDC;
    case 713u: goto L_08B61FE0;
    case 714u: goto L_08B61FE4;
    case 715u: goto L_08B61FE8;
    case 716u: goto L_08B61FEC;
    case 717u: goto L_08B61FF0;
    case 718u: goto L_08B61FF4;
    case 719u: goto L_08B61FF8;
    case 720u: goto L_08B61FFC;
    case 721u: goto L_08B62000;
    case 722u: goto L_08B62004;
    case 723u: goto L_08B62008;
    case 724u: goto L_08B6200C;
    case 725u: goto L_08B62010;
    case 726u: goto L_08B62014;
    case 727u: goto L_08B62018;
    case 728u: goto L_08B6201C;
    case 729u: goto L_08B62020;
    case 730u: goto L_08B62024;
    case 731u: goto L_08B62028;
    case 732u: goto L_08B6202C;
    case 733u: goto L_08B62030;
    case 734u: goto L_08B62034;
    case 735u: goto L_08B62038;
    case 736u: goto L_08B6203C;
    case 737u: goto L_08B62040;
    case 738u: goto L_08B62044;
    case 739u: goto L_08B62048;
    case 740u: goto L_08B6204C;
    case 741u: goto L_08B62050;
    case 742u: goto L_08B62054;
    case 743u: goto L_08B62058;
    case 744u: goto L_08B6205C;
    case 745u: goto L_08B62060;
    case 746u: goto L_08B62064;
    case 747u: goto L_08B62068;
    case 748u: goto L_08B6206C;
    case 749u: goto L_08B62070;
    case 750u: goto L_08B62074;
    case 751u: goto L_08B62078;
    case 752u: goto L_08B6207C;
    case 753u: goto L_08B62080;
    case 754u: goto L_08B62084;
    case 755u: goto L_08B62088;
    case 756u: goto L_08B6208C;
    case 757u: goto L_08B62090;
    case 758u: goto L_08B62094;
    case 759u: goto L_08B62098;
    case 760u: goto L_08B6209C;
    case 761u: goto L_08B620A0;
    case 762u: goto L_08B620A4;
    case 763u: goto L_08B620A8;
    case 764u: goto L_08B620AC;
    case 765u: goto L_08B620B0;
    case 766u: goto L_08B620B4;
    case 767u: goto L_08B620B8;
    case 768u: goto L_08B620BC;
    case 769u: goto L_08B620C0;
    case 770u: goto L_08B620C4;
    case 771u: goto L_08B620C8;
    case 772u: goto L_08B620CC;
    case 773u: goto L_08B620D0;
    case 774u: goto L_08B620D4;
    case 775u: goto L_08B620D8;
    case 776u: goto L_08B620DC;
    case 777u: goto L_08B620E0;
    case 778u: goto L_08B620E4;
    case 779u: goto L_08B620E8;
    case 780u: goto L_08B620EC;
    case 781u: goto L_08B620F0;
    case 782u: goto L_08B620F4;
    case 783u: goto L_08B620F8;
    case 784u: goto L_08B620FC;
    case 785u: goto L_08B62100;
    case 786u: goto L_08B62104;
    case 787u: goto L_08B62108;
    case 788u: goto L_08B6210C;
    case 789u: goto L_08B62110;
    case 790u: goto L_08B62114;
    case 791u: goto L_08B62118;
    case 792u: goto L_08B6211C;
    case 793u: goto L_08B62120;
    case 794u: goto L_08B62124;
    case 795u: goto L_08B62128;
    case 796u: goto L_08B6212C;
    case 797u: goto L_08B62130;
    case 798u: goto L_08B62134;
    case 799u: goto L_08B62138;
    case 800u: goto L_08B6213C;
    case 801u: goto L_08B62140;
    case 802u: goto L_08B62144;
    case 803u: goto L_08B62148;
    case 804u: goto L_08B6214C;
    case 805u: goto L_08B62150;
    case 806u: goto L_08B62154;
    case 807u: goto L_08B62158;
    case 808u: goto L_08B6215C;
    case 809u: goto L_08B62160;
    case 810u: goto L_08B62164;
    case 811u: goto L_08B62168;
    case 812u: goto L_08B6216C;
    case 813u: goto L_08B62170;
    case 814u: goto L_08B62174;
    case 815u: goto L_08B62178;
    case 816u: goto L_08B6217C;
    case 817u: goto L_08B62180;
    case 818u: goto L_08B62184;
    case 819u: goto L_08B62188;
    case 820u: goto L_08B6218C;
    case 821u: goto L_08B62190;
    case 822u: goto L_08B62194;
    case 823u: goto L_08B62198;
    case 824u: goto L_08B6219C;
    case 825u: goto L_08B621A0;
    case 826u: goto L_08B621A4;
    case 827u: goto L_08B621A8;
    case 828u: goto L_08B621AC;
    case 829u: goto L_08B621B0;
    case 830u: goto L_08B621B4;
    case 831u: goto L_08B621B8;
    case 832u: goto L_08B621BC;
    case 833u: goto L_08B621C0;
    case 834u: goto L_08B621C4;
    case 835u: goto L_08B621C8;
    case 836u: goto L_08B621CC;
    case 837u: goto L_08B621D0;
    case 838u: goto L_08B621D4;
    case 839u: goto L_08B621D8;
    case 840u: goto L_08B621DC;
    case 841u: goto L_08B621E0;
    case 842u: goto L_08B621E4;
    case 843u: goto L_08B621E8;
    case 844u: goto L_08B621EC;
    case 845u: goto L_08B621F0;
    case 846u: goto L_08B621F4;
    case 847u: goto L_08B621F8;
    case 848u: goto L_08B621FC;
    case 849u: goto L_08B62200;
    case 850u: goto L_08B62204;
    case 851u: goto L_08B62208;
    case 852u: goto L_08B6220C;
    case 853u: goto L_08B62210;
    case 854u: goto L_08B62214;
    case 855u: goto L_08B62218;
    case 856u: goto L_08B6221C;
    case 857u: goto L_08B62220;
    case 858u: goto L_08B62224;
    case 859u: goto L_08B62228;
    case 860u: goto L_08B6222C;
    case 861u: goto L_08B62230;
    case 862u: goto L_08B62234;
    case 863u: goto L_08B62238;
    case 864u: goto L_08B6223C;
    case 865u: goto L_08B62240;
    case 866u: goto L_08B62244;
    case 867u: goto L_08B62248;
    case 868u: goto L_08B6224C;
    case 869u: goto L_08B62250;
    case 870u: goto L_08B62254;
    case 871u: goto L_08B62258;
    case 872u: goto L_08B6225C;
    case 873u: goto L_08B62260;
    case 874u: goto L_08B62264;
    case 875u: goto L_08B62268;
    case 876u: goto L_08B6226C;
    case 877u: goto L_08B62270;
    case 878u: goto L_08B62274;
    case 879u: goto L_08B62278;
    case 880u: goto L_08B6227C;
    case 881u: goto L_08B62280;
    case 882u: goto L_08B62284;
    case 883u: goto L_08B62288;
    case 884u: goto L_08B6228C;
    case 885u: goto L_08B62290;
    case 886u: goto L_08B62294;
    case 887u: goto L_08B62298;
    case 888u: goto L_08B6229C;
    case 889u: goto L_08B622A0;
    case 890u: goto L_08B622A4;
    case 891u: goto L_08B622A8;
    case 892u: goto L_08B622AC;
    case 893u: goto L_08B622B0;
    case 894u: goto L_08B622B4;
    case 895u: goto L_08B622B8;
    case 896u: goto L_08B622BC;
    case 897u: goto L_08B622C0;
    case 898u: goto L_08B622C4;
    case 899u: goto L_08B622C8;
    case 900u: goto L_08B622CC;
    case 901u: goto L_08B622D0;
    case 902u: goto L_08B622D4;
    case 903u: goto L_08B622D8;
    case 904u: goto L_08B622DC;
    case 905u: goto L_08B622E0;
    case 906u: goto L_08B622E4;
    case 907u: goto L_08B622E8;
    case 908u: goto L_08B622EC;
    case 909u: goto L_08B622F0;
    case 910u: goto L_08B622F4;
    case 911u: goto L_08B622F8;
    case 912u: goto L_08B622FC;
    case 913u: goto L_08B62300;
    case 914u: goto L_08B62304;
    case 915u: goto L_08B62308;
    case 916u: goto L_08B6230C;
    case 917u: goto L_08B62310;
    case 918u: goto L_08B62314;
    case 919u: goto L_08B62318;
    case 920u: goto L_08B6231C;
    case 921u: goto L_08B62320;
    case 922u: goto L_08B62324;
    case 923u: goto L_08B62328;
    case 924u: goto L_08B6232C;
    case 925u: goto L_08B62330;
    case 926u: goto L_08B62334;
    case 927u: goto L_08B62338;
    case 928u: goto L_08B6233C;
    case 929u: goto L_08B62340;
    case 930u: goto L_08B62344;
    case 931u: goto L_08B62348;
    case 932u: goto L_08B6234C;
    case 933u: goto L_08B62350;
    case 934u: goto L_08B62354;
    case 935u: goto L_08B62358;
    case 936u: goto L_08B6235C;
    case 937u: goto L_08B62360;
    case 938u: goto L_08B62364;
    case 939u: goto L_08B62368;
    case 940u: goto L_08B6236C;
    case 941u: goto L_08B62370;
    case 942u: goto L_08B62374;
    case 943u: goto L_08B62378;
    case 944u: goto L_08B6237C;
    case 945u: goto L_08B62380;
    case 946u: goto L_08B62384;
    case 947u: goto L_08B62388;
    case 948u: goto L_08B6238C;
    case 949u: goto L_08B62390;
    case 950u: goto L_08B62394;
    case 951u: goto L_08B62398;
    case 952u: goto L_08B6239C;
    case 953u: goto L_08B623A0;
    case 954u: goto L_08B623A4;
    case 955u: goto L_08B623A8;
    case 956u: goto L_08B623AC;
    case 957u: goto L_08B623B0;
    case 958u: goto L_08B623B4;
    case 959u: goto L_08B623B8;
    case 960u: goto L_08B623BC;
    case 961u: goto L_08B623C0;
    case 962u: goto L_08B623C4;
    case 963u: goto L_08B623C8;
    case 964u: goto L_08B623CC;
    case 965u: goto L_08B623D0;
    case 966u: goto L_08B623D4;
    case 967u: goto L_08B623D8;
    case 968u: goto L_08B623DC;
    case 969u: goto L_08B623E0;
    case 970u: goto L_08B623E4;
    case 971u: goto L_08B623E8;
    case 972u: goto L_08B623EC;
    case 973u: goto L_08B623F0;
    case 974u: goto L_08B623F4;
    case 975u: goto L_08B623F8;
    case 976u: goto L_08B623FC;
    case 977u: goto L_08B62400;
    case 978u: goto L_08B62404;
    case 979u: goto L_08B62408;
    case 980u: goto L_08B6240C;
    case 981u: goto L_08B62410;
    case 982u: goto L_08B62414;
    case 983u: goto L_08B62418;
    case 984u: goto L_08B6241C;
    case 985u: goto L_08B62420;
    case 986u: goto L_08B62424;
    case 987u: goto L_08B62428;
    case 988u: goto L_08B6242C;
    case 989u: goto L_08B62430;
    case 990u: goto L_08B62434;
    case 991u: goto L_08B62438;
    case 992u: goto L_08B6243C;
    case 993u: goto L_08B62440;
    case 994u: goto L_08B62444;
    case 995u: goto L_08B62448;
    case 996u: goto L_08B6244C;
    case 997u: goto L_08B62450;
    case 998u: goto L_08B62454;
    case 999u: goto L_08B62458;
    case 1000u: goto L_08B6245C;
    case 1001u: goto L_08B62460;
    case 1002u: goto L_08B62464;
    case 1003u: goto L_08B62468;
    case 1004u: goto L_08B6246C;
    case 1005u: goto L_08B62470;
    case 1006u: goto L_08B62474;
    case 1007u: goto L_08B62478;
    case 1008u: goto L_08B6247C;
    case 1009u: goto L_08B62480;
    case 1010u: goto L_08B62484;
    case 1011u: goto L_08B62488;
    case 1012u: goto L_08B6248C;
    case 1013u: goto L_08B62490;
    case 1014u: goto L_08B62494;
    case 1015u: goto L_08B62498;
    case 1016u: goto L_08B6249C;
    case 1017u: goto L_08B624A0;
    case 1018u: goto L_08B624A4;
    case 1019u: goto L_08B624A8;
    case 1020u: goto L_08B624AC;
    case 1021u: goto L_08B624B0;
    case 1022u: goto L_08B624B4;
    case 1023u: goto L_08B624B8;
    case 1024u: goto L_08B624BC;
    case 1025u: goto L_08B624C0;
    case 1026u: goto L_08B624C4;
    case 1027u: goto L_08B624C8;
    case 1028u: goto L_08B624CC;
    case 1029u: goto L_08B624D0;
    case 1030u: goto L_08B624D4;
    case 1031u: goto L_08B624D8;
    case 1032u: goto L_08B624DC;
    case 1033u: goto L_08B624E0;
    case 1034u: goto L_08B624E4;
    case 1035u: goto L_08B624E8;
    case 1036u: goto L_08B624EC;
    case 1037u: goto L_08B624F0;
    case 1038u: goto L_08B624F4;
    case 1039u: goto L_08B624F8;
    case 1040u: goto L_08B624FC;
    case 1041u: goto L_08B62500;
    case 1042u: goto L_08B62504;
    case 1043u: goto L_08B62508;
    case 1044u: goto L_08B6250C;
    case 1045u: goto L_08B62510;
    case 1046u: goto L_08B62514;
    case 1047u: goto L_08B62518;
    case 1048u: goto L_08B6251C;
    case 1049u: goto L_08B62520;
    case 1050u: goto L_08B62524;
    case 1051u: goto L_08B62528;
    case 1052u: goto L_08B6252C;
    case 1053u: goto L_08B62530;
    case 1054u: goto L_08B62534;
    case 1055u: goto L_08B62538;
    case 1056u: goto L_08B6253C;
    case 1057u: goto L_08B62540;
    case 1058u: goto L_08B62544;
    case 1059u: goto L_08B62548;
    case 1060u: goto L_08B6254C;
    case 1061u: goto L_08B62550;
    case 1062u: goto L_08B62554;
    case 1063u: goto L_08B62558;
    case 1064u: goto L_08B6255C;
    case 1065u: goto L_08B62560;
    case 1066u: goto L_08B62564;
    case 1067u: goto L_08B62568;
    case 1068u: goto L_08B6256C;
    case 1069u: goto L_08B62570;
    case 1070u: goto L_08B62574;
    case 1071u: goto L_08B62578;
    case 1072u: goto L_08B6257C;
    case 1073u: goto L_08B62580;
    case 1074u: goto L_08B62584;
    case 1075u: goto L_08B62588;
    case 1076u: goto L_08B6258C;
    case 1077u: goto L_08B62590;
    case 1078u: goto L_08B62594;
    case 1079u: goto L_08B62598;
    case 1080u: goto L_08B6259C;
    case 1081u: goto L_08B625A0;
    case 1082u: goto L_08B625A4;
    case 1083u: goto L_08B625A8;
    case 1084u: goto L_08B625AC;
    case 1085u: goto L_08B625B0;
    case 1086u: goto L_08B625B4;
    case 1087u: goto L_08B625B8;
    case 1088u: goto L_08B625BC;
    case 1089u: goto L_08B625C0;
    case 1090u: goto L_08B625C4;
    case 1091u: goto L_08B625C8;
    case 1092u: goto L_08B625CC;
    case 1093u: goto L_08B625D0;
    case 1094u: goto L_08B625D4;
    case 1095u: goto L_08B625D8;
    case 1096u: goto L_08B625DC;
    case 1097u: goto L_08B625E0;
    case 1098u: goto L_08B625E4;
    case 1099u: goto L_08B625E8;
    case 1100u: goto L_08B625EC;
    case 1101u: goto L_08B625F0;
    case 1102u: goto L_08B625F4;
    case 1103u: goto L_08B625F8;
    case 1104u: goto L_08B625FC;
    case 1105u: goto L_08B62600;
    case 1106u: goto L_08B62604;
    case 1107u: goto L_08B62608;
    case 1108u: goto L_08B6260C;
    case 1109u: goto L_08B62610;
    case 1110u: goto L_08B62614;
    case 1111u: goto L_08B62618;
    case 1112u: goto L_08B6261C;
    case 1113u: goto L_08B62620;
    case 1114u: goto L_08B62624;
    case 1115u: goto L_08B62628;
    case 1116u: goto L_08B6262C;
    case 1117u: goto L_08B62630;
    case 1118u: goto L_08B62634;
    case 1119u: goto L_08B62638;
    case 1120u: goto L_08B6263C;
    case 1121u: goto L_08B62640;
    case 1122u: goto L_08B62644;
    case 1123u: goto L_08B62648;
    case 1124u: goto L_08B6264C;
    case 1125u: goto L_08B62650;
    case 1126u: goto L_08B62654;
    case 1127u: goto L_08B62658;
    case 1128u: goto L_08B6265C;
    case 1129u: goto L_08B62660;
    case 1130u: goto L_08B62664;
    case 1131u: goto L_08B62668;
    case 1132u: goto L_08B6266C;
    case 1133u: goto L_08B62670;
    case 1134u: goto L_08B62674;
    case 1135u: goto L_08B62678;
    case 1136u: goto L_08B6267C;
    case 1137u: goto L_08B62680;
    case 1138u: goto L_08B62684;
    case 1139u: goto L_08B62688;
    case 1140u: goto L_08B6268C;
    case 1141u: goto L_08B62690;
    case 1142u: goto L_08B62694;
    case 1143u: goto L_08B62698;
    case 1144u: goto L_08B6269C;
    case 1145u: goto L_08B626A0;
    case 1146u: goto L_08B626A4;
    case 1147u: goto L_08B626A8;
    case 1148u: goto L_08B626AC;
    case 1149u: goto L_08B626B0;
    case 1150u: goto L_08B626B4;
    case 1151u: goto L_08B626B8;
    case 1152u: goto L_08B626BC;
    case 1153u: goto L_08B626C0;
    case 1154u: goto L_08B626C4;
    case 1155u: goto L_08B626C8;
    case 1156u: goto L_08B626CC;
    case 1157u: goto L_08B626D0;
    case 1158u: goto L_08B626D4;
    case 1159u: goto L_08B626D8;
    case 1160u: goto L_08B626DC;
    case 1161u: goto L_08B626E0;
    case 1162u: goto L_08B626E4;
    case 1163u: goto L_08B626E8;
    case 1164u: goto L_08B626EC;
    case 1165u: goto L_08B626F0;
    case 1166u: goto L_08B626F4;
    case 1167u: goto L_08B626F8;
    case 1168u: goto L_08B626FC;
    case 1169u: goto L_08B62700;
    case 1170u: goto L_08B62704;
    case 1171u: goto L_08B62708;
    case 1172u: goto L_08B6270C;
    case 1173u: goto L_08B62710;
    case 1174u: goto L_08B62714;
    case 1175u: goto L_08B62718;
    case 1176u: goto L_08B6271C;
    case 1177u: goto L_08B62720;
    case 1178u: goto L_08B62724;
    case 1179u: goto L_08B62728;
    case 1180u: goto L_08B6272C;
    case 1181u: goto L_08B62730;
    case 1182u: goto L_08B62734;
    case 1183u: goto L_08B62738;
    case 1184u: goto L_08B6273C;
    case 1185u: goto L_08B62740;
    case 1186u: goto L_08B62744;
    case 1187u: goto L_08B62748;
    case 1188u: goto L_08B6274C;
    case 1189u: goto L_08B62750;
    case 1190u: goto L_08B62754;
    case 1191u: goto L_08B62758;
    case 1192u: goto L_08B6275C;
    case 1193u: goto L_08B62760;
    case 1194u: goto L_08B62764;
    case 1195u: goto L_08B62768;
    case 1196u: goto L_08B6276C;
    case 1197u: goto L_08B62770;
    case 1198u: goto L_08B62774;
    case 1199u: goto L_08B62778;
    case 1200u: goto L_08B6277C;
    case 1201u: goto L_08B62780;
    case 1202u: goto L_08B62784;
    case 1203u: goto L_08B62788;
    case 1204u: goto L_08B6278C;
    case 1205u: goto L_08B62790;
    case 1206u: goto L_08B62794;
    case 1207u: goto L_08B62798;
    case 1208u: goto L_08B6279C;
    case 1209u: goto L_08B627A0;
    case 1210u: goto L_08B627A4;
    case 1211u: goto L_08B627A8;
    case 1212u: goto L_08B627AC;
    case 1213u: goto L_08B627B0;
    case 1214u: goto L_08B627B4;
    case 1215u: goto L_08B627B8;
    case 1216u: goto L_08B627BC;
    case 1217u: goto L_08B627C0;
    case 1218u: goto L_08B627C4;
    case 1219u: goto L_08B627C8;
    case 1220u: goto L_08B627CC;
    case 1221u: goto L_08B627D0;
    case 1222u: goto L_08B627D4;
    case 1223u: goto L_08B627D8;
    case 1224u: goto L_08B627DC;
    case 1225u: goto L_08B627E0;
    case 1226u: goto L_08B627E4;
    case 1227u: goto L_08B627E8;
    case 1228u: goto L_08B627EC;
    case 1229u: goto L_08B627F0;
    case 1230u: goto L_08B627F4;
    case 1231u: goto L_08B627F8;
    case 1232u: goto L_08B627FC;
    case 1233u: goto L_08B62800;
    case 1234u: goto L_08B62804;
    case 1235u: goto L_08B62808;
    case 1236u: goto L_08B6280C;
    case 1237u: goto L_08B62810;
    case 1238u: goto L_08B62814;
    case 1239u: goto L_08B62818;
    case 1240u: goto L_08B6281C;
    case 1241u: goto L_08B62820;
    case 1242u: goto L_08B62824;
    case 1243u: goto L_08B62828;
    case 1244u: goto L_08B6282C;
    case 1245u: goto L_08B62830;
    case 1246u: goto L_08B62834;
    case 1247u: goto L_08B62838;
    case 1248u: goto L_08B6283C;
    case 1249u: goto L_08B62840;
    case 1250u: goto L_08B62844;
    case 1251u: goto L_08B62848;
    case 1252u: goto L_08B6284C;
    case 1253u: goto L_08B62850;
    case 1254u: goto L_08B62854;
    case 1255u: goto L_08B62858;
    case 1256u: goto L_08B6285C;
    case 1257u: goto L_08B62860;
    case 1258u: goto L_08B62864;
    case 1259u: goto L_08B62868;
    case 1260u: goto L_08B6286C;
    case 1261u: goto L_08B62870;
    case 1262u: goto L_08B62874;
    case 1263u: goto L_08B62878;
    case 1264u: goto L_08B6287C;
    case 1265u: goto L_08B62880;
    case 1266u: goto L_08B62884;
    case 1267u: goto L_08B62888;
    case 1268u: goto L_08B6288C;
    case 1269u: goto L_08B62890;
    case 1270u: goto L_08B62894;
    case 1271u: goto L_08B62898;
    case 1272u: goto L_08B6289C;
    case 1273u: goto L_08B628A0;
    case 1274u: goto L_08B628A4;
    case 1275u: goto L_08B628A8;
    case 1276u: goto L_08B628AC;
    case 1277u: goto L_08B628B0;
    case 1278u: goto L_08B628B4;
    case 1279u: goto L_08B628B8;
    case 1280u: goto L_08B628BC;
    case 1281u: goto L_08B628C0;
    case 1282u: goto L_08B628C4;
    case 1283u: goto L_08B628C8;
    case 1284u: goto L_08B628CC;
    case 1285u: goto L_08B628D0;
    case 1286u: goto L_08B628D4;
    case 1287u: goto L_08B628D8;
    case 1288u: goto L_08B628DC;
    case 1289u: goto L_08B628E0;
    case 1290u: goto L_08B628E4;
    case 1291u: goto L_08B628E8;
    case 1292u: goto L_08B628EC;
    case 1293u: goto L_08B628F0;
    case 1294u: goto L_08B628F4;
    case 1295u: goto L_08B628F8;
    case 1296u: goto L_08B628FC;
    case 1297u: goto L_08B62900;
    case 1298u: goto L_08B62904;
    case 1299u: goto L_08B62908;
    case 1300u: goto L_08B6290C;
    case 1301u: goto L_08B62910;
    case 1302u: goto L_08B62914;
    case 1303u: goto L_08B62918;
    case 1304u: goto L_08B6291C;
    case 1305u: goto L_08B62920;
    case 1306u: goto L_08B62924;
    case 1307u: goto L_08B62928;
    case 1308u: goto L_08B6292C;
    case 1309u: goto L_08B62930;
    case 1310u: goto L_08B62934;
    case 1311u: goto L_08B62938;
    case 1312u: goto L_08B6293C;
    case 1313u: goto L_08B62940;
    case 1314u: goto L_08B62944;
    case 1315u: goto L_08B62948;
    case 1316u: goto L_08B6294C;
    case 1317u: goto L_08B62950;
    case 1318u: goto L_08B62954;
    case 1319u: goto L_08B62958;
    case 1320u: goto L_08B6295C;
    case 1321u: goto L_08B62960;
    case 1322u: goto L_08B62964;
    case 1323u: goto L_08B62968;
    case 1324u: goto L_08B6296C;
    case 1325u: goto L_08B62970;
    case 1326u: goto L_08B62974;
    case 1327u: goto L_08B62978;
    case 1328u: goto L_08B6297C;
    case 1329u: goto L_08B62980;
    case 1330u: goto L_08B62984;
    case 1331u: goto L_08B62988;
    case 1332u: goto L_08B6298C;
    case 1333u: goto L_08B62990;
    case 1334u: goto L_08B62994;
    case 1335u: goto L_08B62998;
    case 1336u: goto L_08B6299C;
    case 1337u: goto L_08B629A0;
    case 1338u: goto L_08B629A4;
    case 1339u: goto L_08B629A8;
    case 1340u: goto L_08B629AC;
    case 1341u: goto L_08B629B0;
    case 1342u: goto L_08B629B4;
    case 1343u: goto L_08B629B8;
    case 1344u: goto L_08B629BC;
    case 1345u: goto L_08B629C0;
    case 1346u: goto L_08B629C4;
    case 1347u: goto L_08B629C8;
    case 1348u: goto L_08B629CC;
    case 1349u: goto L_08B629D0;
    case 1350u: goto L_08B629D4;
    case 1351u: goto L_08B629D8;
    case 1352u: goto L_08B629DC;
    case 1353u: goto L_08B629E0;
    case 1354u: goto L_08B629E4;
    case 1355u: goto L_08B629E8;
    case 1356u: goto L_08B629EC;
    case 1357u: goto L_08B629F0;
    case 1358u: goto L_08B629F4;
    case 1359u: goto L_08B629F8;
    case 1360u: goto L_08B629FC;
    case 1361u: goto L_08B62A00;
    case 1362u: goto L_08B62A04;
    case 1363u: goto L_08B62A08;
    case 1364u: goto L_08B62A0C;
    case 1365u: goto L_08B62A10;
    case 1366u: goto L_08B62A14;
    case 1367u: goto L_08B62A18;
    case 1368u: goto L_08B62A1C;
    case 1369u: goto L_08B62A20;
    case 1370u: goto L_08B62A24;
    case 1371u: goto L_08B62A28;
    case 1372u: goto L_08B62A2C;
    case 1373u: goto L_08B62A30;
    case 1374u: goto L_08B62A34;
    case 1375u: goto L_08B62A38;
    case 1376u: goto L_08B62A3C;
    case 1377u: goto L_08B62A40;
    case 1378u: goto L_08B62A44;
    case 1379u: goto L_08B62A48;
    case 1380u: goto L_08B62A4C;
    case 1381u: goto L_08B62A50;
    case 1382u: goto L_08B62A54;
    case 1383u: goto L_08B62A58;
    case 1384u: goto L_08B62A5C;
    case 1385u: goto L_08B62A60;
    case 1386u: goto L_08B62A64;
    case 1387u: goto L_08B62A68;
    case 1388u: goto L_08B62A6C;
    case 1389u: goto L_08B62A70;
    case 1390u: goto L_08B62A74;
    case 1391u: goto L_08B62A78;
    case 1392u: goto L_08B62A7C;
    case 1393u: goto L_08B62A80;
    case 1394u: goto L_08B62A84;
    case 1395u: goto L_08B62A88;
    case 1396u: goto L_08B62A8C;
    case 1397u: goto L_08B62A90;
    case 1398u: goto L_08B62A94;
    case 1399u: goto L_08B62A98;
    case 1400u: goto L_08B62A9C;
    case 1401u: goto L_08B62AA0;
    case 1402u: goto L_08B62AA4;
    case 1403u: goto L_08B62AA8;
    case 1404u: goto L_08B62AAC;
    case 1405u: goto L_08B62AB0;
    case 1406u: goto L_08B62AB4;
    case 1407u: goto L_08B62AB8;
    case 1408u: goto L_08B62ABC;
    case 1409u: goto L_08B62AC0;
    case 1410u: goto L_08B62AC4;
    case 1411u: goto L_08B62AC8;
    case 1412u: goto L_08B62ACC;
    case 1413u: goto L_08B62AD0;
    case 1414u: goto L_08B62AD4;
    case 1415u: goto L_08B62AD8;
    case 1416u: goto L_08B62ADC;
    case 1417u: goto L_08B62AE0;
    case 1418u: goto L_08B62AE4;
    case 1419u: goto L_08B62AE8;
    case 1420u: goto L_08B62AEC;
    case 1421u: goto L_08B62AF0;
    case 1422u: goto L_08B62AF4;
    case 1423u: goto L_08B62AF8;
    case 1424u: goto L_08B62AFC;
    case 1425u: goto L_08B62B00;
    case 1426u: goto L_08B62B04;
    case 1427u: goto L_08B62B08;
    case 1428u: goto L_08B62B0C;
    case 1429u: goto L_08B62B10;
    case 1430u: goto L_08B62B14;
    case 1431u: goto L_08B62B18;
    case 1432u: goto L_08B62B1C;
    case 1433u: goto L_08B62B20;
    case 1434u: goto L_08B62B24;
    case 1435u: goto L_08B62B28;
    case 1436u: goto L_08B62B2C;
    case 1437u: goto L_08B62B30;
    case 1438u: goto L_08B62B34;
    case 1439u: goto L_08B62B38;
    case 1440u: goto L_08B62B3C;
    case 1441u: goto L_08B62B40;
    case 1442u: goto L_08B62B44;
    case 1443u: goto L_08B62B48;
    case 1444u: goto L_08B62B4C;
    case 1445u: goto L_08B62B50;
    case 1446u: goto L_08B62B54;
    case 1447u: goto L_08B62B58;
    case 1448u: goto L_08B62B5C;
    case 1449u: goto L_08B62B60;
    case 1450u: goto L_08B62B64;
    case 1451u: goto L_08B62B68;
    case 1452u: goto L_08B62B6C;
    case 1453u: goto L_08B62B70;
    case 1454u: goto L_08B62B74;
    case 1455u: goto L_08B62B78;
    case 1456u: goto L_08B62B7C;
    case 1457u: goto L_08B62B80;
    case 1458u: goto L_08B62B84;
    case 1459u: goto L_08B62B88;
    case 1460u: goto L_08B62B8C;
    case 1461u: goto L_08B62B90;
    case 1462u: goto L_08B62B94;
    case 1463u: goto L_08B62B98;
    case 1464u: goto L_08B62B9C;
    case 1465u: goto L_08B62BA0;
    case 1466u: goto L_08B62BA4;
    case 1467u: goto L_08B62BA8;
    case 1468u: goto L_08B62BAC;
    case 1469u: goto L_08B62BB0;
    case 1470u: goto L_08B62BB4;
    case 1471u: goto L_08B62BB8;
    case 1472u: goto L_08B62BBC;
    case 1473u: goto L_08B62BC0;
    case 1474u: goto L_08B62BC4;
    case 1475u: goto L_08B62BC8;
    case 1476u: goto L_08B62BCC;
    case 1477u: goto L_08B62BD0;
    case 1478u: goto L_08B62BD4;
    case 1479u: goto L_08B62BD8;
    case 1480u: goto L_08B62BDC;
    case 1481u: goto L_08B62BE0;
    case 1482u: goto L_08B62BE4;
    case 1483u: goto L_08B62BE8;
    case 1484u: goto L_08B62BEC;
    case 1485u: goto L_08B62BF0;
    case 1486u: goto L_08B62BF4;
    case 1487u: goto L_08B62BF8;
    case 1488u: goto L_08B62BFC;
    case 1489u: goto L_08B62C00;
    case 1490u: goto L_08B62C04;
    case 1491u: goto L_08B62C08;
    case 1492u: goto L_08B62C0C;
    case 1493u: goto L_08B62C10;
    case 1494u: goto L_08B62C14;
    case 1495u: goto L_08B62C18;
    case 1496u: goto L_08B62C1C;
    case 1497u: goto L_08B62C20;
    case 1498u: goto L_08B62C24;
    case 1499u: goto L_08B62C28;
    case 1500u: goto L_08B62C2C;
    case 1501u: goto L_08B62C30;
    case 1502u: goto L_08B62C34;
    case 1503u: goto L_08B62C38;
    case 1504u: goto L_08B62C3C;
    case 1505u: goto L_08B62C40;
    case 1506u: goto L_08B62C44;
    case 1507u: goto L_08B62C48;
    case 1508u: goto L_08B62C4C;
    case 1509u: goto L_08B62C50;
    case 1510u: goto L_08B62C54;
    case 1511u: goto L_08B62C58;
    case 1512u: goto L_08B62C5C;
    case 1513u: goto L_08B62C60;
    case 1514u: goto L_08B62C64;
    case 1515u: goto L_08B62C68;
    case 1516u: goto L_08B62C6C;
    case 1517u: goto L_08B62C70;
    case 1518u: goto L_08B62C74;
    case 1519u: goto L_08B62C78;
    case 1520u: goto L_08B62C7C;
    case 1521u: goto L_08B62C80;
    case 1522u: goto L_08B62C84;
    case 1523u: goto L_08B62C88;
    case 1524u: goto L_08B62C8C;
    case 1525u: goto L_08B62C90;
    case 1526u: goto L_08B62C94;
    case 1527u: goto L_08B62C98;
    case 1528u: goto L_08B62C9C;
    case 1529u: goto L_08B62CA0;
    case 1530u: goto L_08B62CA4;
    case 1531u: goto L_08B62CA8;
    case 1532u: goto L_08B62CAC;
    case 1533u: goto L_08B62CB0;
    case 1534u: goto L_08B62CB4;
    case 1535u: goto L_08B62CB8;
    case 1536u: goto L_08B62CBC;
    case 1537u: goto L_08B62CC0;
    case 1538u: goto L_08B62CC4;
    case 1539u: goto L_08B62CC8;
    case 1540u: goto L_08B62CCC;
    case 1541u: goto L_08B62CD0;
    case 1542u: goto L_08B62CD4;
    case 1543u: goto L_08B62CD8;
    case 1544u: goto L_08B62CDC;
    case 1545u: goto L_08B62CE0;
    case 1546u: goto L_08B62CE4;
    case 1547u: goto L_08B62CE8;
    case 1548u: goto L_08B62CEC;
    case 1549u: goto L_08B62CF0;
    case 1550u: goto L_08B62CF4;
    case 1551u: goto L_08B62CF8;
    case 1552u: goto L_08B62CFC;
    case 1553u: goto L_08B62D00;
    case 1554u: goto L_08B62D04;
    case 1555u: goto L_08B62D08;
    case 1556u: goto L_08B62D0C;
    case 1557u: goto L_08B62D10;
    case 1558u: goto L_08B62D14;
    case 1559u: goto L_08B62D18;
    case 1560u: goto L_08B62D1C;
    case 1561u: goto L_08B62D20;
    case 1562u: goto L_08B62D24;
    case 1563u: goto L_08B62D28;
    case 1564u: goto L_08B62D2C;
    case 1565u: goto L_08B62D30;
    case 1566u: goto L_08B62D34;
    case 1567u: goto L_08B62D38;
    case 1568u: goto L_08B62D3C;
    case 1569u: goto L_08B62D40;
    case 1570u: goto L_08B62D44;
    case 1571u: goto L_08B62D48;
    case 1572u: goto L_08B62D4C;
    case 1573u: goto L_08B62D50;
    case 1574u: goto L_08B62D54;
    case 1575u: goto L_08B62D58;
    case 1576u: goto L_08B62D5C;
    case 1577u: goto L_08B62D60;
    case 1578u: goto L_08B62D64;
    case 1579u: goto L_08B62D68;
    case 1580u: goto L_08B62D6C;
    case 1581u: goto L_08B62D70;
    case 1582u: goto L_08B62D74;
    case 1583u: goto L_08B62D78;
    case 1584u: goto L_08B62D7C;
    case 1585u: goto L_08B62D80;
    case 1586u: goto L_08B62D84;
    case 1587u: goto L_08B62D88;
    case 1588u: goto L_08B62D8C;
    case 1589u: goto L_08B62D90;
    case 1590u: goto L_08B62D94;
    case 1591u: goto L_08B62D98;
    case 1592u: goto L_08B62D9C;
    case 1593u: goto L_08B62DA0;
    case 1594u: goto L_08B62DA4;
    case 1595u: goto L_08B62DA8;
    case 1596u: goto L_08B62DAC;
    case 1597u: goto L_08B62DB0;
    case 1598u: goto L_08B62DB4;
    case 1599u: goto L_08B62DB8;
    case 1600u: goto L_08B62DBC;
    case 1601u: goto L_08B62DC0;
    case 1602u: goto L_08B62DC4;
    case 1603u: goto L_08B62DC8;
    case 1604u: goto L_08B62DCC;
    case 1605u: goto L_08B62DD0;
    case 1606u: goto L_08B62DD4;
    case 1607u: goto L_08B62DD8;
    case 1608u: goto L_08B62DDC;
    case 1609u: goto L_08B62DE0;
    case 1610u: goto L_08B62DE4;
    case 1611u: goto L_08B62DE8;
    case 1612u: goto L_08B62DEC;
    case 1613u: goto L_08B62DF0;
    case 1614u: goto L_08B62DF4;
    case 1615u: goto L_08B62DF8;
    case 1616u: goto L_08B62DFC;
    case 1617u: goto L_08B62E00;
    case 1618u: goto L_08B62E04;
    case 1619u: goto L_08B62E08;
    case 1620u: goto L_08B62E0C;
    case 1621u: goto L_08B62E10;
    case 1622u: goto L_08B62E14;
    case 1623u: goto L_08B62E18;
    case 1624u: goto L_08B62E1C;
    case 1625u: goto L_08B62E20;
    case 1626u: goto L_08B62E24;
    case 1627u: goto L_08B62E28;
    case 1628u: goto L_08B62E2C;
    case 1629u: goto L_08B62E30;
    case 1630u: goto L_08B62E34;
    case 1631u: goto L_08B62E38;
    case 1632u: goto L_08B62E3C;
    case 1633u: goto L_08B62E40;
    case 1634u: goto L_08B62E44;
    case 1635u: goto L_08B62E48;
    case 1636u: goto L_08B62E4C;
    case 1637u: goto L_08B62E50;
    case 1638u: goto L_08B62E54;
    case 1639u: goto L_08B62E58;
    case 1640u: goto L_08B62E5C;
    case 1641u: goto L_08B62E60;
    case 1642u: goto L_08B62E64;
    case 1643u: goto L_08B62E68;
    case 1644u: goto L_08B62E6C;
    case 1645u: goto L_08B62E70;
    case 1646u: goto L_08B62E74;
    case 1647u: goto L_08B62E78;
    case 1648u: goto L_08B62E7C;
    case 1649u: goto L_08B62E80;
    case 1650u: goto L_08B62E84;
    case 1651u: goto L_08B62E88;
    case 1652u: goto L_08B62E8C;
    case 1653u: goto L_08B62E90;
    case 1654u: goto L_08B62E94;
    case 1655u: goto L_08B62E98;
    case 1656u: goto L_08B62E9C;
    case 1657u: goto L_08B62EA0;
    case 1658u: goto L_08B62EA4;
    case 1659u: goto L_08B62EA8;
    case 1660u: goto L_08B62EAC;
    case 1661u: goto L_08B62EB0;
    case 1662u: goto L_08B62EB4;
    case 1663u: goto L_08B62EB8;
    case 1664u: goto L_08B62EBC;
    case 1665u: goto L_08B62EC0;
    case 1666u: goto L_08B62EC4;
    case 1667u: goto L_08B62EC8;
    case 1668u: goto L_08B62ECC;
    case 1669u: goto L_08B62ED0;
    case 1670u: goto L_08B62ED4;
    case 1671u: goto L_08B62ED8;
    case 1672u: goto L_08B62EDC;
    case 1673u: goto L_08B62EE0;
    case 1674u: goto L_08B62EE4;
    case 1675u: goto L_08B62EE8;
    case 1676u: goto L_08B62EEC;
    case 1677u: goto L_08B62EF0;
    case 1678u: goto L_08B62EF4;
    case 1679u: goto L_08B62EF8;
    case 1680u: goto L_08B62EFC;
    case 1681u: goto L_08B62F00;
    case 1682u: goto L_08B62F04;
    case 1683u: goto L_08B62F08;
    case 1684u: goto L_08B62F0C;
    case 1685u: goto L_08B62F10;
    case 1686u: goto L_08B62F14;
    case 1687u: goto L_08B62F18;
    case 1688u: goto L_08B62F1C;
    case 1689u: goto L_08B62F20;
    case 1690u: goto L_08B62F24;
    case 1691u: goto L_08B62F28;
    case 1692u: goto L_08B62F2C;
    case 1693u: goto L_08B62F30;
    case 1694u: goto L_08B62F34;
    case 1695u: goto L_08B62F38;
    case 1696u: goto L_08B62F3C;
    case 1697u: goto L_08B62F40;
    case 1698u: goto L_08B62F44;
    case 1699u: goto L_08B62F48;
    case 1700u: goto L_08B62F4C;
    case 1701u: goto L_08B62F50;
    case 1702u: goto L_08B62F54;
    case 1703u: goto L_08B62F58;
    case 1704u: goto L_08B62F5C;
    case 1705u: goto L_08B62F60;
    case 1706u: goto L_08B62F64;
    case 1707u: goto L_08B62F68;
    case 1708u: goto L_08B62F6C;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B614C0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(212), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B614C4;
L_08B614C4:
    ctx.gpr[31] = (0x08B614CCu);
    ctx.gpr[4] = (0u | 3840u);
    ctx.pc = 0x0885CD44u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B614CCu) goto L_08B614CC;
    return;
L_08B614C8:
    ctx.gpr[4] = (0u | 3840u);
    goto L_08B614CC;
L_08B614CC:
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
    goto L_08B614D0;
L_08B614D0:
    if (ctx.gpr[4] != 0u) {
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(208), ctx.gpr[16]);
        goto L_08B614E8;
    }
    goto L_08B614D8;
L_08B614D4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(208), ctx.gpr[16]);
    goto L_08B614D8;
L_08B614D8:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B619A0;
      }
      goto L_08B614E0;
    }
L_08B614DC:
    // nop
    goto L_08B614E0;
L_08B614E0:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B619A0;
      }
      goto L_08B614E8;
    }
L_08B614E4:
    // nop
    goto L_08B614E8;
L_08B614E8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(204), ctx.gpr[4]);
    goto L_08B614EC;
L_08B614EC:
    ctx.gpr[17] = (ctx.gpr[4] | 0u);
    goto L_08B614F0;
L_08B614F0:
    ctx.gpr[18] = (2205u << 16u);
    goto L_08B614F4;
L_08B614F4:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(24256)));
    goto L_08B614F8;
L_08B614F8:
    ctx.gpr[31] = (0x08B61500u);
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(1824));
    ctx.pc = 0x0885EA98u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61500u) goto L_08B61500;
    return;
L_08B614FC:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(1824));
    goto L_08B61500;
L_08B61500:
    ctx.gpr[19] = (ctx.gpr[2] | 0u);
    goto L_08B61504;
L_08B61504:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(24256)));
    goto L_08B61508;
L_08B61508:
    ctx.gpr[31] = (0x08B61510u);
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(1824));
    ctx.pc = 0x0885EA90u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61510u) goto L_08B61510;
    return;
L_08B6150C:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(1824));
    goto L_08B61510;
L_08B61510:
    ctx.gpr[4] = (ctx.gpr[29] | 0u);
    goto L_08B61514;
L_08B61514:
    ctx.gpr[5] = (ctx.gpr[19] | 0u);
    goto L_08B61518;
L_08B61518:
    ctx.gpr[31] = (0x08B61520u);
    ctx.gpr[6] = (ctx.gpr[2] | 0u);
    ctx.pc = 0x089A38FCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61520u) goto L_08B61520;
    return;
L_08B6151C:
    ctx.gpr[6] = (ctx.gpr[2] | 0u);
    goto L_08B61520;
L_08B61520:
    ctx.fpr[12] = std::bit_cast<float>(0u);
    goto L_08B61524;
L_08B61524:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61528;
L_08B61528:
    { const std::uint32_t vfpu_address = ctx.gpr[29] + static_cast<std::uint32_t>(0);
      float vfpu_value[4]{
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 0u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 4u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 8u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 12u))};
      ctx.write_vfpu_vector_ct<0u, 4u>(vfpu_value); }
    goto L_08B6152C;
L_08B6152C:
    ctx.execute_vfpu_vdot_ct<1u, 0u, 0u, 3u>();
    goto L_08B61530;
L_08B61530:
    { float vfpu_value[4]{};
      ctx.write_vfpu_vector_with_destination_prefix_ct<33u, 1u>(vfpu_value); }
    goto L_08B61534;
L_08B61534:
    ctx.execute_vfpu_vcmp_ct<1u, 0u, 1u, 8u>();
    goto L_08B61538;
L_08B61538:
    { float vfpu_s[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<1u, 1u, 0u>(vfpu_s);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = std::fabs(std::sqrt(vfpu_s[i]));
      ctx.write_vfpu_vector_with_destination_prefix_ct<1u, 1u>(vfpu_d); }
    goto L_08B6153C;
L_08B6153C:
    ctx.gpr[4] = (ctx.gpr[29] + static_cast<std::uint32_t>(172));
    goto L_08B61540;
L_08B61540:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), ctx.vfpu_scalar_bits_ct<1u>());
    goto L_08B61544;
L_08B61544:
    { float vfpu_s[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<1u, 1u, 0u>(vfpu_s);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = 1.0f / vfpu_s[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<1u, 1u>(vfpu_d); }
    goto L_08B61548;
L_08B61548:
    ctx.execute_vfpu_vcmov_ct<1u, 33u, 1u, 0u, false>();
    goto L_08B6154C;
L_08B6154C:
    ctx.vfpu_ctrl[2u] = 0x0000083Fu;
    goto L_08B61550;
L_08B61550:
    ctx.execute_vfpu_vscl_ct<0u, 0u, 1u, 3u>();
    goto L_08B61554;
L_08B61554:
    { float vfpu_value[4]{}; ctx.read_vfpu_vector_ct<0u, 4u>(vfpu_value);
      const std::uint32_t vfpu_address = ctx.gpr[29] + static_cast<std::uint32_t>(0);
      aot_mem.aot_store32(vfpu_address + 0u, std::bit_cast<std::uint32_t>(vfpu_value[0]));
      aot_mem.aot_store32(vfpu_address + 4u, std::bit_cast<std::uint32_t>(vfpu_value[1]));
      aot_mem.aot_store32(vfpu_address + 8u, std::bit_cast<std::uint32_t>(vfpu_value[2]));
      aot_mem.aot_store32(vfpu_address + 12u, std::bit_cast<std::uint32_t>(vfpu_value[3])); }
    goto L_08B61558;
L_08B61558:
    ctx.gpr[6] = (2480u << 16u);
    goto L_08B6155C;
L_08B6155C:
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(-31520));
    goto L_08B61560;
L_08B61560:
    ctx.gpr[4] = (ctx.gpr[29] | 0u);
    goto L_08B61564;
L_08B61564:
    ctx.gpr[31] = (0x08B6156Cu);
    ctx.gpr[5] = (ctx.gpr[29] | 0u);
    ctx.pc = 0x089A3B30u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6156Cu) goto L_08B6156C;
    return;
L_08B61568:
    ctx.gpr[5] = (ctx.gpr[29] | 0u);
    goto L_08B6156C;
L_08B6156C:
    ctx.gpr[4] = (2230u << 16u);
    goto L_08B61570;
L_08B61570:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(6824)));
    goto L_08B61574;
L_08B61574:
    ctx.gpr[4] = (ctx.gpr[29] | 0u);
    goto L_08B61578;
L_08B61578:
    ctx.gpr[31] = (0x08B61580u);
    ctx.gpr[5] = (ctx.gpr[29] | 0u);
    ctx.pc = 0x089A3A44u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61580u) goto L_08B61580;
    return;
L_08B6157C:
    ctx.gpr[5] = (ctx.gpr[29] | 0u);
    goto L_08B61580;
L_08B61580:
    ctx.gpr[18] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(20)));
    goto L_08B61584;
L_08B61584:
    ctx.gpr[21] = (0u | 0u);
    goto L_08B61588;
L_08B61588:
    ctx.gpr[19] = (2230u << 16u);
    goto L_08B6158C;
L_08B6158C:
    ctx.gpr[4] = (17279u << 16u);
    goto L_08B61590;
L_08B61590:
    ctx.fpr[12] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B61594;
L_08B61594:
    ctx.gpr[4] = (20224u << 16u);
    goto L_08B61598;
L_08B61598:
    ctx.fpr[13] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B6159C;
L_08B6159C:
    ctx.gpr[23] = (32768u << 16u);
    goto L_08B615A0;
L_08B615A0:
    ctx.gpr[30] = (256u << 16u);
    goto L_08B615A4;
L_08B615A4:
    ctx.gpr[30] = (ctx.gpr[30] + static_cast<std::uint32_t>(-1));
    goto L_08B615A8;
L_08B615A8:
    ctx.gpr[20] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B615AC;
L_08B615AC:
    ctx.gpr[22] = (2230u << 16u);
    goto L_08B615B0;
L_08B615B0:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(16)));
    goto L_08B615B4;
L_08B615B4:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[19] + static_cast<std::uint32_t>(6860)));
    goto L_08B615B8;
L_08B615B8:
    ctx.set_fpu_condition((ctx.fpr[14] < ctx.fpr[15]));
    goto L_08B615BC;
L_08B615BC:
    // nop
    goto L_08B615C0;
L_08B615C0:
    if (!ctx.fpu_condition()) {
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(12)));
        goto L_08B6162C;
    }
    goto L_08B615C8;
L_08B615C4:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(12)));
    goto L_08B615C8;
L_08B615C8:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(16)));
    goto L_08B615CC;
L_08B615CC:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[19] + static_cast<std::uint32_t>(6860)));
    goto L_08B615D0;
L_08B615D0:
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    goto L_08B615D4;
L_08B615D4:
    ctx.fpr[14] = ctx.fpr[14] / ctx.fpr[15];
    goto L_08B615D8;
L_08B615D8:
    ctx.set_fpu_condition((ctx.fpr[14] < ctx.fpr[13]));
    goto L_08B615DC;
L_08B615DC:
    // nop
    goto L_08B615E0;
L_08B615E0:
    if (!ctx.fpu_condition()) {
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(16)));
        goto L_08B61604;
    }
    goto L_08B615E8;
L_08B615E4:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(16)));
    goto L_08B615E8;
L_08B615E8:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(16)));
    goto L_08B615EC;
L_08B615EC:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[19] + static_cast<std::uint32_t>(6860)));
    goto L_08B615F0;
L_08B615F0:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B615F4;
L_08B615F4:
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[14];
    goto L_08B615F8;
L_08B615F8:
    ctx.fpr[12] = std::bit_cast<float>(ctx.fpu_float_to_word_ct<1u>(ctx.fpr[12]));
    goto L_08B615FC;
L_08B615FC:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[16] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
      if (branch_taken) {
          goto L_08B61620;
      }
      goto L_08B61604;
    }
L_08B61600:
    ctx.gpr[16] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61604;
L_08B61604:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[19] + static_cast<std::uint32_t>(6860)));
    goto L_08B61608;
L_08B61608:
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B6160C;
L_08B6160C:
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[15];
    goto L_08B61610;
L_08B61610:
    ctx.fpr[12] = ctx.fpr[12] - ctx.fpr[13];
    goto L_08B61614;
L_08B61614:
    ctx.fpr[12] = std::bit_cast<float>(ctx.fpu_float_to_word_ct<1u>(ctx.fpr[12]));
    goto L_08B61618;
L_08B61618:
    ctx.gpr[16] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B6161C;
L_08B6161C:
    ctx.gpr[16] = (ctx.gpr[16] + ctx.gpr[23]);
    goto L_08B61620;
L_08B61620:
    ctx.gpr[16] = (ctx.gpr[16] << 24u);
    goto L_08B61624;
L_08B61624:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[16] = (ctx.gpr[16] | ctx.gpr[30]);
      if (branch_taken) {
          goto L_08B616C8;
      }
      goto L_08B6162C;
    }
L_08B61628:
    ctx.gpr[16] = (ctx.gpr[16] | ctx.gpr[30]);
    goto L_08B6162C;
L_08B6162C:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(16)));
    goto L_08B61630;
L_08B61630:
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[19] + static_cast<std::uint32_t>(6860)));
    goto L_08B61634;
L_08B61634:
    ctx.fpr[14] = ctx.fpr[14] - ctx.fpr[15];
    goto L_08B61638;
L_08B61638:
    ctx.set_fpu_condition((ctx.fpr[14] < ctx.fpr[16]));
    goto L_08B6163C;
L_08B6163C:
    // nop
    goto L_08B61640;
L_08B61640:
    { const bool branch_taken = !ctx.fpu_condition();
    // nop
      if (branch_taken) {
          goto L_08B616C4;
      }
      goto L_08B61648;
    }
L_08B61644:
    // nop
    goto L_08B61648;
L_08B61648:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(12)));
    goto L_08B6164C;
L_08B6164C:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(16)));
    goto L_08B61650;
L_08B61650:
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[19] + static_cast<std::uint32_t>(6860)));
    goto L_08B61654;
L_08B61654:
    ctx.fpr[14] = ctx.fpr[14] - ctx.fpr[15];
    goto L_08B61658;
L_08B61658:
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    goto L_08B6165C;
L_08B6165C:
    ctx.fpr[14] = ctx.fpr[14] / ctx.fpr[16];
    goto L_08B61660;
L_08B61660:
    ctx.set_fpu_condition((ctx.fpr[14] < ctx.fpr[13]));
    goto L_08B61664;
L_08B61664:
    // nop
    goto L_08B61668;
L_08B61668:
    if (!ctx.fpu_condition()) {
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(12)));
        goto L_08B61694;
    }
    goto L_08B61670;
L_08B6166C:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(12)));
    goto L_08B61670;
L_08B61670:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(12)));
    goto L_08B61674;
L_08B61674:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(16)));
    goto L_08B61678;
L_08B61678:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[19] + static_cast<std::uint32_t>(6860)));
    goto L_08B6167C;
L_08B6167C:
    ctx.fpr[13] = ctx.fpr[13] - ctx.fpr[14];
    goto L_08B61680;
L_08B61680:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B61684;
L_08B61684:
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[15];
    goto L_08B61688;
L_08B61688:
    ctx.fpr[12] = std::bit_cast<float>(ctx.fpu_float_to_word_ct<1u>(ctx.fpr[12]));
    goto L_08B6168C;
L_08B6168C:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[16] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
      if (branch_taken) {
          goto L_08B616B8;
      }
      goto L_08B61694;
    }
L_08B61690:
    ctx.gpr[16] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61694;
L_08B61694:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(16)));
    goto L_08B61698;
L_08B61698:
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[19] + static_cast<std::uint32_t>(6860)));
    goto L_08B6169C;
L_08B6169C:
    ctx.fpr[14] = ctx.fpr[14] - ctx.fpr[15];
    goto L_08B616A0;
L_08B616A0:
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B616A4;
L_08B616A4:
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[16];
    goto L_08B616A8;
L_08B616A8:
    ctx.fpr[12] = ctx.fpr[12] - ctx.fpr[13];
    goto L_08B616AC;
L_08B616AC:
    ctx.fpr[12] = std::bit_cast<float>(ctx.fpu_float_to_word_ct<1u>(ctx.fpr[12]));
    goto L_08B616B0;
L_08B616B0:
    ctx.gpr[16] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B616B4;
L_08B616B4:
    ctx.gpr[16] = (ctx.gpr[16] + ctx.gpr[23]);
    goto L_08B616B8;
L_08B616B8:
    ctx.gpr[16] = (ctx.gpr[16] << 24u);
    goto L_08B616BC;
L_08B616BC:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[16] = (ctx.gpr[16] | ctx.gpr[30]);
      if (branch_taken) {
          goto L_08B616C8;
      }
      goto L_08B616C4;
    }
L_08B616C0:
    ctx.gpr[16] = (ctx.gpr[16] | ctx.gpr[30]);
    goto L_08B616C4;
L_08B616C4:
    ctx.gpr[16] = (0u + static_cast<std::uint32_t>(-1));
    goto L_08B616C8;
L_08B616C8:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(20)));
    goto L_08B616CC;
L_08B616CC:
    ctx.fpr[20] = std::bit_cast<float>(0u);
    goto L_08B616D0;
L_08B616D0:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(4), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B616D4;
L_08B616D4:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B616D8;
L_08B616D8:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(8), ctx.gpr[16]);
    goto L_08B616DC;
L_08B616DC:
    ctx.gpr[4] = (ctx.gpr[29] + static_cast<std::uint32_t>(76));
    goto L_08B616E0;
L_08B616E0:
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    goto L_08B616E4;
L_08B616E4:
    ctx.gpr[31] = (0x08B616ECu);
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    ctx.pc = 0x089A34F4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B616ECu) goto L_08B616EC;
    return;
L_08B616E8:
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    goto L_08B616EC;
L_08B616EC:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(76)));
    goto L_08B616F0;
L_08B616F0:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(80)));
    goto L_08B616F4;
L_08B616F4:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(84)));
    goto L_08B616F8;
L_08B616F8:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B616FC;
L_08B616FC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(200), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61700;
L_08B61700:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B61704;
L_08B61704:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(196), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B61708;
L_08B61708:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B6170C;
L_08B6170C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[4]);
    goto L_08B61710;
L_08B61710:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(192), std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B61714;
L_08B61714:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[5]);
    goto L_08B61718;
L_08B61718:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[6]);
    goto L_08B6171C;
L_08B6171C:
    ctx.gpr[4] = (ctx.gpr[17] + static_cast<std::uint32_t>(12));
    goto L_08B61720;
L_08B61720:
    ctx.gpr[31] = (0x08B61728u);
    ctx.gpr[5] = (ctx.gpr[20] | 0u);
    ctx.pc = 0x089A34C0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61728u) goto L_08B61728;
    return;
L_08B61724:
    ctx.gpr[5] = (ctx.gpr[20] | 0u);
    goto L_08B61728;
L_08B61728:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(20)));
    goto L_08B6172C;
L_08B6172C:
    ctx.gpr[4] = (16256u << 16u);
    goto L_08B61730;
L_08B61730:
    ctx.fpr[22] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B61734;
L_08B61734:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(24), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61738;
L_08B61738:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(28), std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B6173C;
L_08B6173C:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(32), ctx.gpr[16]);
    goto L_08B61740;
L_08B61740:
    ctx.gpr[4] = (ctx.gpr[29] + static_cast<std::uint32_t>(100));
    goto L_08B61744;
L_08B61744:
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    goto L_08B61748;
L_08B61748:
    ctx.gpr[31] = (0x08B61750u);
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    ctx.pc = 0x089A3528u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61750u) goto L_08B61750;
    return;
L_08B6174C:
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    goto L_08B61750;
L_08B61750:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(100)));
    goto L_08B61754;
L_08B61754:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(104)));
    goto L_08B61758;
L_08B61758:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(108)));
    goto L_08B6175C;
L_08B6175C:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61760;
L_08B61760:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(188), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61764;
L_08B61764:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B61768;
L_08B61768:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(184), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B6176C;
L_08B6176C:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B61770;
L_08B61770:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[4]);
    goto L_08B61774;
L_08B61774:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(180), std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B61778;
L_08B61778:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[5]);
    goto L_08B6177C;
L_08B6177C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[6]);
    goto L_08B61780;
L_08B61780:
    ctx.gpr[4] = (ctx.gpr[17] + static_cast<std::uint32_t>(36));
    goto L_08B61784;
L_08B61784:
    ctx.gpr[31] = (0x08B6178Cu);
    ctx.gpr[5] = (ctx.gpr[20] | 0u);
    ctx.pc = 0x089A34C0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6178Cu) goto L_08B6178C;
    return;
L_08B61788:
    ctx.gpr[5] = (ctx.gpr[20] | 0u);
    goto L_08B6178C;
L_08B6178C:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(20)));
    goto L_08B61790;
L_08B61790:
    ctx.gpr[4] = (15616u << 16u);
    goto L_08B61794;
L_08B61794:
    ctx.fpr[24] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B61798;
L_08B61798:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(52), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B6179C;
L_08B6179C:
    ctx.fpr[12] = ctx.fpr[12] + ctx.fpr[24];
    goto L_08B617A0;
L_08B617A0:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(56), ctx.gpr[16]);
    goto L_08B617A4;
L_08B617A4:
    ctx.gpr[4] = (ctx.gpr[29] + static_cast<std::uint32_t>(124));
    goto L_08B617A8;
L_08B617A8:
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    goto L_08B617AC;
L_08B617AC:
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    goto L_08B617B0;
L_08B617B0:
    ctx.gpr[31] = (0x08B617B8u);
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(48), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.pc = 0x089A34F4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B617B8u) goto L_08B617B8;
    return;
L_08B617B4:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(48), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B617B8;
L_08B617B8:
    ctx.fpr[30] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(124)));
    goto L_08B617BC;
L_08B617BC:
    ctx.fpr[28] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(128)));
    goto L_08B617C0;
L_08B617C0:
    ctx.fpr[26] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(132)));
    goto L_08B617C4;
L_08B617C4:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[30]));
    goto L_08B617C8;
L_08B617C8:
    ctx.gpr[7] = (std::bit_cast<std::uint32_t>(ctx.fpr[28]));
    goto L_08B617CC;
L_08B617CC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[6]);
    goto L_08B617D0;
L_08B617D0:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[26]));
    goto L_08B617D4;
L_08B617D4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[7]);
    goto L_08B617D8;
L_08B617D8:
    ctx.gpr[4] = (ctx.gpr[17] + static_cast<std::uint32_t>(60));
    goto L_08B617DC;
L_08B617DC:
    ctx.gpr[5] = (ctx.gpr[20] | 0u);
    goto L_08B617E0;
L_08B617E0:
    ctx.gpr[31] = (0x08B617E8u);
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[6]);
    ctx.pc = 0x089A34C0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B617E8u) goto L_08B617E8;
    return;
L_08B617E4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[6]);
    goto L_08B617E8;
L_08B617E8:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(64)));
    goto L_08B617EC;
L_08B617EC:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[22] + static_cast<std::uint32_t>(6828)));
    goto L_08B617F0;
L_08B617F0:
    ctx.fpr[12] = ctx.fpr[12] + ctx.fpr[13];
    goto L_08B617F4;
L_08B617F4:
    ctx.gpr[4] = (ctx.gpr[29] + static_cast<std::uint32_t>(148));
    goto L_08B617F8;
L_08B617F8:
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    goto L_08B617FC;
L_08B617FC:
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    goto L_08B61800;
L_08B61800:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(64), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61804;
L_08B61804:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(20)));
    goto L_08B61808;
L_08B61808:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(76), std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B6180C;
L_08B6180C:
    ctx.fpr[12] = ctx.fpr[12] + ctx.fpr[24];
    goto L_08B61810;
L_08B61810:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(80), ctx.gpr[16]);
    goto L_08B61814;
L_08B61814:
    ctx.gpr[31] = (0x08B6181Cu);
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(72), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.pc = 0x089A3528u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6181Cu) goto L_08B6181C;
    return;
L_08B61818:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(72), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B6181C;
L_08B6181C:
    ctx.fpr[24] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(148)));
    goto L_08B61820;
L_08B61820:
    ctx.fpr[22] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(152)));
    goto L_08B61824;
L_08B61824:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(156)));
    goto L_08B61828;
L_08B61828:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[24]));
    goto L_08B6182C;
L_08B6182C:
    ctx.gpr[7] = (std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B61830;
L_08B61830:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[6]);
    goto L_08B61834;
L_08B61834:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B61838;
L_08B61838:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[7]);
    goto L_08B6183C;
L_08B6183C:
    ctx.gpr[4] = (ctx.gpr[17] + static_cast<std::uint32_t>(84));
    goto L_08B61840;
L_08B61840:
    ctx.gpr[5] = (ctx.gpr[20] | 0u);
    goto L_08B61844;
L_08B61844:
    ctx.gpr[31] = (0x08B6184Cu);
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[6]);
    ctx.pc = 0x089A34C0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6184Cu) goto L_08B6184C;
    return;
L_08B61848:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[6]);
    goto L_08B6184C;
L_08B6184C:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(88)));
    goto L_08B61850;
L_08B61850:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[22] + static_cast<std::uint32_t>(6828)));
    goto L_08B61854;
L_08B61854:
    ctx.gpr[5] = (17279u << 16u);
    goto L_08B61858;
L_08B61858:
    ctx.fpr[12] = ctx.fpr[12] + ctx.fpr[13];
    goto L_08B6185C;
L_08B6185C:
    ctx.gpr[21] = (ctx.gpr[21] + static_cast<std::uint32_t>(1));
    goto L_08B61860;
L_08B61860:
    ctx.gpr[18] = (ctx.gpr[18] + static_cast<std::uint32_t>(24));
    goto L_08B61864;
L_08B61864:
    ctx.gpr[4] = (static_cast<std::int32_t>(ctx.gpr[21]) < 40 ? 1u : 0u);
    goto L_08B61868;
L_08B61868:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(88), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B6186C;
L_08B6186C:
    ctx.fpr[12] = std::bit_cast<float>(ctx.gpr[5]);
    goto L_08B61870;
L_08B61870:
    ctx.gpr[17] = (ctx.gpr[17] + static_cast<std::uint32_t>(96));
    goto L_08B61874;
L_08B61874:
    ctx.gpr[5] = (20224u << 16u);
    goto L_08B61878;
L_08B61878:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.fpr[13] = std::bit_cast<float>(ctx.gpr[5]);
      if (branch_taken) {
          goto L_08B615B0;
      }
      goto L_08B61880;
    }
L_08B6187C:
    ctx.fpr[13] = std::bit_cast<float>(ctx.gpr[5]);
    goto L_08B61880;
L_08B61880:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(200)));
    goto L_08B61884;
L_08B61884:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(196)));
    goto L_08B61888;
L_08B61888:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(192)));
    goto L_08B6188C;
L_08B6188C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61890;
L_08B61890:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(188)));
    goto L_08B61894;
L_08B61894:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(32), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B61898;
L_08B61898:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(184)));
    goto L_08B6189C;
L_08B6189C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(36), std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B618A0;
L_08B618A0:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(180)));
    goto L_08B618A4;
L_08B618A4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(40), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B618A8;
L_08B618A8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(44), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B618AC;
L_08B618AC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(48), std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B618B0;
L_08B618B0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(52), std::bit_cast<std::uint32_t>(ctx.fpr[30]));
    goto L_08B618B4;
L_08B618B4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(56), std::bit_cast<std::uint32_t>(ctx.fpr[28]));
    goto L_08B618B8;
L_08B618B8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(60), std::bit_cast<std::uint32_t>(ctx.fpr[26]));
    goto L_08B618BC;
L_08B618BC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(64), std::bit_cast<std::uint32_t>(ctx.fpr[24]));
    goto L_08B618C0;
L_08B618C0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(68), std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B618C4;
L_08B618C4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(72), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B618C8;
L_08B618C8:
    ctx.gpr[31] = (0x08B618D0u);
    ctx.gpr[4] = (0u | 0u);
    ctx.pc = 0x0899FDC4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B618D0u) goto L_08B618D0;
    return;
L_08B618CC:
    ctx.gpr[4] = (0u | 0u);
    goto L_08B618D0;
L_08B618D0:
    ctx.gpr[31] = (0x08B618D8u);
    ctx.gpr[4] = (0u | 4u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B618D8u) goto L_08B618D8;
    return;
L_08B618D4:
    ctx.gpr[4] = (0u | 4u);
    goto L_08B618D8;
L_08B618D8:
    ctx.gpr[31] = (0x08B618E0u);
    ctx.gpr[4] = (0u | 9u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B618E0u) goto L_08B618E0;
    return;
L_08B618DC:
    ctx.gpr[4] = (0u | 9u);
    goto L_08B618E0;
L_08B618E0:
    ctx.gpr[31] = (0x08B618E8u);
    ctx.gpr[4] = (0u | 1u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B618E8u) goto L_08B618E8;
    return;
L_08B618E4:
    ctx.gpr[4] = (0u | 1u);
    goto L_08B618E8;
L_08B618E8:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(212)));
    goto L_08B618EC;
L_08B618EC:
    ctx.gpr[4] = (17279u << 16u);
    goto L_08B618F0;
L_08B618F0:
    ctx.fpr[13] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B618F4;
L_08B618F4:
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B618F8;
L_08B618F8:
    ctx.fpr[12] = std::bit_cast<float>(ctx.fpu_float_to_word_ct<1u>(ctx.fpr[12]));
    goto L_08B618FC;
L_08B618FC:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61900;
L_08B61900:
    ctx.gpr[4] = (ctx.gpr[4] & 255u);
    goto L_08B61904;
L_08B61904:
    ctx.gpr[4] = (ctx.gpr[4] << 24u);
    goto L_08B61908;
L_08B61908:
    ctx.gpr[31] = (0x08B61910u);
    ctx.gpr[4] = (ctx.gpr[4] | ctx.gpr[30]);
    ctx.pc = 0x089A0C20u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61910u) goto L_08B61910;
    return;
L_08B6190C:
    ctx.gpr[4] = (ctx.gpr[4] | ctx.gpr[30]);
    goto L_08B61910;
L_08B61910:
    ctx.gpr[31] = (0x08B61918u);
    ctx.gpr[4] = (0u | 1u);
    ctx.pc = 0x0899FFC8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61918u) goto L_08B61918;
    return;
L_08B61914:
    ctx.gpr[4] = (0u | 1u);
    goto L_08B61918;
L_08B61918:
    ctx.gpr[31] = (0x08B61920u);
    ctx.gpr[4] = (0u | 10u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61920u) goto L_08B61920;
    return;
L_08B6191C:
    ctx.gpr[4] = (0u | 10u);
    goto L_08B61920;
L_08B61920:
    ctx.gpr[31] = (0x08B61928u);
    ctx.gpr[4] = (0u | 11u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61928u) goto L_08B61928;
    return;
L_08B61924:
    ctx.gpr[4] = (0u | 11u);
    goto L_08B61928;
L_08B61928:
    ctx.gpr[31] = (0x08B61930u);
    ctx.gpr[4] = (0u | 12u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61930u) goto L_08B61930;
    return;
L_08B6192C:
    ctx.gpr[4] = (0u | 12u);
    goto L_08B61930;
L_08B61930:
    ctx.gpr[31] = (0x08B61938u);
    ctx.gpr[4] = (0u | 13u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61938u) goto L_08B61938;
    return;
L_08B61934:
    ctx.gpr[4] = (0u | 13u);
    goto L_08B61938;
L_08B61938:
    ctx.gpr[31] = (0x08B61940u);
    ctx.gpr[4] = (0u | 14u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61940u) goto L_08B61940;
    return;
L_08B6193C:
    ctx.gpr[4] = (0u | 14u);
    goto L_08B61940;
L_08B61940:
    ctx.gpr[4] = (0u | 0u);
    goto L_08B61944;
L_08B61944:
    ctx.gpr[5] = (0u | 2u);
    goto L_08B61948;
L_08B61948:
    ctx.gpr[6] = (0u | 3u);
    goto L_08B6194C;
L_08B6194C:
    ctx.gpr[7] = (0u | 0u);
    goto L_08B61950;
L_08B61950:
    ctx.gpr[31] = (0x08B61958u);
    ctx.gpr[8] = (0u | 0u);
    ctx.pc = 0x089A12A4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61958u) goto L_08B61958;
    return;
L_08B61954:
    ctx.gpr[8] = (0u | 0u);
    goto L_08B61958;
L_08B61958:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(208)));
    goto L_08B6195C;
L_08B6195C:
    ctx.gpr[31] = (0x08B61964u);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(16)));
    ctx.pc = 0x0899D2F8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61964u) goto L_08B61964;
    return;
L_08B61960:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(16)));
    goto L_08B61964;
L_08B61964:
    ctx.gpr[31] = (0x08B6196Cu);
    ctx.gpr[4] = (0u | 2u);
    ctx.pc = 0x089A296Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6196Cu) goto L_08B6196C;
    return;
L_08B61968:
    ctx.gpr[4] = (0u | 2u);
    goto L_08B6196C;
L_08B6196C:
    ctx.gpr[31] = (0x08B61974u);
    // nop
    ctx.pc = 0x089A250Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61974u) goto L_08B61974;
    return;
L_08B61970:
    // nop
    goto L_08B61974;
L_08B61974:
    ctx.gpr[31] = (0x08B6197Cu);
    ctx.gpr[4] = (0u | 1u);
    ctx.pc = 0x089A119Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6197Cu) goto L_08B6197C;
    return;
L_08B61978:
    ctx.gpr[4] = (0u | 1u);
    goto L_08B6197C;
L_08B6197C:
    ctx.gpr[4] = (0u | 4u);
    goto L_08B61980;
L_08B61980:
    ctx.gpr[5] = (0u | 415u);
    goto L_08B61984;
L_08B61984:
    ctx.gpr[6] = (0u | 4u);
    goto L_08B61988;
L_08B61988:
    ctx.gpr[9] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(204)));
    goto L_08B6198C;
L_08B6198C:
    ctx.gpr[7] = (0u | 40u);
    goto L_08B61990;
L_08B61990:
    ctx.gpr[31] = (0x08B61998u);
    ctx.gpr[8] = (0u | 0u);
    ctx.pc = 0x089A05F0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61998u) goto L_08B61998;
    return;
L_08B61994:
    ctx.gpr[8] = (0u | 0u);
    goto L_08B61998;
L_08B61998:
    ctx.gpr[31] = (0x08B619A0u);
    ctx.gpr[4] = (0u | 0u);
    ctx.pc = 0x089A119Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B619A0u) goto L_08B619A0;
    return;
L_08B6199C:
    ctx.gpr[4] = (0u | 0u);
    goto L_08B619A0;
L_08B619A0:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(216)));
    goto L_08B619A4;
L_08B619A4:
    ctx.fpr[22] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(220)));
    goto L_08B619A8;
L_08B619A8:
    ctx.fpr[24] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(224)));
    goto L_08B619AC;
L_08B619AC:
    ctx.fpr[26] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(228)));
    goto L_08B619B0;
L_08B619B0:
    ctx.fpr[28] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(232)));
    goto L_08B619B4;
L_08B619B4:
    ctx.fpr[30] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(236)));
    goto L_08B619B8;
L_08B619B8:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(240)));
    goto L_08B619BC;
L_08B619BC:
    ctx.gpr[17] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(244)));
    goto L_08B619C0;
L_08B619C0:
    ctx.gpr[18] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(248)));
    goto L_08B619C4;
L_08B619C4:
    ctx.gpr[19] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(252)));
    goto L_08B619C8;
L_08B619C8:
    ctx.gpr[20] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(256)));
    goto L_08B619CC;
L_08B619CC:
    ctx.gpr[21] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(260)));
    goto L_08B619D0;
L_08B619D0:
    ctx.gpr[22] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(264)));
    goto L_08B619D4;
L_08B619D4:
    ctx.gpr[23] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(268)));
    goto L_08B619D8;
L_08B619D8:
    ctx.gpr[30] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(272)));
    goto L_08B619DC;
L_08B619DC:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(276)));
    goto L_08B619E0;
L_08B619E0:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(288));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B619E4:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(288));
    goto L_08B619E8;
L_08B619E8:
    // nop
    goto L_08B619EC;
L_08B619EC:
    // nop
    goto L_08B619F0;
L_08B619F0:
    // nop
    goto L_08B619F4;
L_08B619F4:
    // nop
    ctx.pc = 0x02D84530u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B619F8:
    // nop
    goto L_08B619FC;
L_08B619FC:
    // nop
    ctx.pc = 0x02D87230u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A00:
    // nop
    goto L_08B61A04;
L_08B61A04:
    // nop
    ctx.pc = 0x02D84440u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A08:
    // nop
    goto L_08B61A0C;
L_08B61A0C:
    // nop
    ctx.pc = 0x02D87050u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A10:
    // nop
    goto L_08B61A14;
L_08B61A14:
    // nop
    ctx.pc = 0x02D87390u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A18:
    // nop
    goto L_08B61A1C;
L_08B61A1C:
    // nop
    ctx.pc = 0x02D84380u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A20:
    // nop
    goto L_08B61A24;
L_08B61A24:
    // nop
    ctx.pc = 0x02D873B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A28:
    // nop
    goto L_08B61A2C;
L_08B61A2C:
    // nop
    ctx.pc = 0x02D843A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A30:
    // nop
    goto L_08B61A34;
L_08B61A34:
    // nop
    ctx.pc = 0x02D843C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A38:
    // nop
    goto L_08B61A3C;
L_08B61A3C:
    // nop
    ctx.pc = 0x02D843E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A40:
    // nop
    goto L_08B61A44;
L_08B61A44:
    // nop
    ctx.pc = 0x02D874F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A48:
    // nop
    goto L_08B61A4C;
L_08B61A4C:
    // nop
    ctx.pc = 0x02D84400u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A50:
    // nop
    goto L_08B61A54;
L_08B61A54:
    // nop
    ctx.pc = 0x02D84420u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A58:
    // nop
    goto L_08B61A5C;
L_08B61A5C:
    // nop
    ctx.pc = 0x02D4C120u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A60:
    // nop
    goto L_08B61A64;
L_08B61A64:
    // nop
    ctx.pc = 0x02D84680u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A68:
    // nop
    goto L_08B61A6C;
L_08B61A6C:
    // nop
    ctx.pc = 0x02D87940u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A70:
    // nop
    goto L_08B61A74;
L_08B61A74:
    // nop
    ctx.pc = 0x02D87A80u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A78:
    // nop
    goto L_08B61A7C;
L_08B61A7C:
    // nop
    ctx.pc = 0x02D848A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A80:
    // nop
    goto L_08B61A84;
L_08B61A84:
    // nop
    ctx.pc = 0x02D851C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A88:
    // nop
    goto L_08B61A8C;
L_08B61A8C:
    // nop
    ctx.pc = 0x02D89790u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A90:
    // nop
    goto L_08B61A94;
L_08B61A94:
    // nop
    ctx.pc = 0x02D8A1C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61A98:
    // nop
    goto L_08B61A9C;
L_08B61A9C:
    // nop
    ctx.pc = 0x02D8ABA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61AA0:
    // nop
    goto L_08B61AA4;
L_08B61AA4:
    rt.unsupported(0x08B61AA8u, 0x40000000u, "unknown not lowered yet"); return;
    ctx.pc = 0x02D8B3E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61AA8:
    rt.unsupported(0x08B61AA8u, 0x40000000u, "unknown not lowered yet"); return;
L_08B61AAC:
    rt.unsupported(0x08B61AACu, 0x41400000u, "unknown not lowered yet"); return;
L_08B61AB0:
    rt.unsupported(0x08B61AB0u, 0x41F00000u, "unknown not lowered yet"); return;
L_08B61AB4:
    rt.unsupported(0x08B61AB4u, 0x42480000u, "unknown not lowered yet"); return;
L_08B61AB8:
    rt.execute_extra_instruction(ctx, 0x08B61AB8u, 0xC1200000u);
    goto L_08B61ABC;
L_08B61ABC:
    rt.unsupported(0x08B61ABCu, 0x41200000u, "unknown not lowered yet"); return;
L_08B61AC0:
    rt.execute_extra_instruction(ctx, 0x08B61AC0u, 0xC0000000u);
    goto L_08B61AC4;
L_08B61AC4:
    rt.execute_extra_instruction(ctx, 0x08B61AC4u, 0xC1200000u);
    goto L_08B61AC8;
L_08B61AC8:
    rt.unsupported(0x08B61AC8u, 0x41200000u, "unknown not lowered yet"); return;
L_08B61ACC:
    rt.unsupported(0x08B61ACCu, 0x41200000u, "unknown not lowered yet"); return;
L_08B61AD0:
    ctx.gpr[3] = (ctx.gpr[24] ^ 4719u);
    goto L_08B61AD4;
L_08B61AD4:
    rt.unsupported(0x08B61AD4u, 0x6E696172u, "vfpu3 not lowered yet"); return;
L_08B61AD8:
    ctx.gpr[17] = (ctx.gpr[17] < static_cast<std::uint32_t>(12383) ? 1u : 0u);
    goto L_08B61ADC;
L_08B61ADC:
    ctx.gpr[13] = (~(ctx.gpr[3] | ctx.gpr[13]));
    goto L_08B61AE0;
L_08B61AE0:
    jump_target = ctx.gpr[31];
    // nop
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61AE4:
    // nop
    goto L_08B61AE8;
L_08B61AE8:
    jump_target = ctx.gpr[31];
    // nop
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61AEC:
    // nop
    goto L_08B61AF0;
L_08B61AF0:
    jump_target = ctx.gpr[31];
    // nop
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61AF4:
    // nop
    goto L_08B61AF8;
L_08B61AF8:
    jump_target = ctx.gpr[31];
    // nop
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61AFC:
    // nop
    goto L_08B61B00;
L_08B61B00:
    jump_target = ctx.gpr[31];
    // nop
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61B04:
    // nop
    goto L_08B61B08;
L_08B61B08:
    jump_target = ctx.gpr[31];
    // nop
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61B0C:
    // nop
    goto L_08B61B10;
L_08B61B10:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B61B14;
L_08B61B14:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B61B18;
L_08B61B18:
    ctx.gpr[31] = (0x08B61B20u);
    // nop
    goto L_08B61C08;
L_08B61B1C:
    // nop
    goto L_08B61B20;
L_08B61B20:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B61B24;
L_08B61B24:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61B28:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B61B2C;
L_08B61B2C:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B61B30;
L_08B61B30:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B61B34;
L_08B61B34:
    ctx.gpr[31] = (0x08B61B3Cu);
    // nop
    goto L_08B61C5C;
L_08B61B38:
    // nop
    goto L_08B61B3C;
L_08B61B3C:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B61B40;
L_08B61B40:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61B44:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B61B48;
L_08B61B48:
    // nop
    goto L_08B61B4C;
L_08B61B4C:
    // nop
    goto L_08B61B50;
L_08B61B50:
    // nop
    goto L_08B61B54;
L_08B61B54:
    // nop
    ctx.pc = 0x02D86CB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61B58:
    // nop
    goto L_08B61B5C;
L_08B61B5C:
    // nop
    ctx.pc = 0x02D87230u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61B60:
    // nop
    goto L_08B61B64;
L_08B61B64:
    // nop
    ctx.pc = 0x02D86C40u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61B68:
    // nop
    goto L_08B61B6C;
L_08B61B6C:
    // nop
    ctx.pc = 0x02D87050u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61B70:
    // nop
    goto L_08B61B74;
L_08B61B74:
    // nop
    ctx.pc = 0x02D87390u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61B78:
    // nop
    goto L_08B61B7C;
L_08B61B7C:
    // nop
    ctx.pc = 0x02D86B80u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61B80:
    // nop
    goto L_08B61B84;
L_08B61B84:
    // nop
    ctx.pc = 0x02D873B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61B88:
    // nop
    goto L_08B61B8C;
L_08B61B8C:
    // nop
    ctx.pc = 0x02D86BA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61B90:
    // nop
    goto L_08B61B94;
L_08B61B94:
    // nop
    ctx.pc = 0x02D86BC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61B98:
    // nop
    goto L_08B61B9C;
L_08B61B9C:
    // nop
    ctx.pc = 0x02D86BE0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BA0:
    // nop
    goto L_08B61BA4;
L_08B61BA4:
    // nop
    ctx.pc = 0x02D874F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BA8:
    // nop
    goto L_08B61BAC;
L_08B61BAC:
    // nop
    ctx.pc = 0x02D86C00u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BB0:
    // nop
    goto L_08B61BB4;
L_08B61BB4:
    // nop
    ctx.pc = 0x02D86C20u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BB8:
    // nop
    goto L_08B61BBC;
L_08B61BBC:
    // nop
    ctx.pc = 0x02D4C120u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BC0:
    // nop
    goto L_08B61BC4;
L_08B61BC4:
    // nop
    ctx.pc = 0x02D87730u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BC8:
    // nop
    goto L_08B61BCC;
L_08B61BCC:
    // nop
    ctx.pc = 0x02D87940u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BD0:
    // nop
    goto L_08B61BD4;
L_08B61BD4:
    // nop
    ctx.pc = 0x02D87A80u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BD8:
    // nop
    goto L_08B61BDC;
L_08B61BDC:
    // nop
    ctx.pc = 0x02D87CC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BE0:
    // nop
    goto L_08B61BE4;
L_08B61BE4:
    // nop
    ctx.pc = 0x02D88C50u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BE8:
    // nop
    goto L_08B61BEC;
L_08B61BEC:
    // nop
    ctx.pc = 0x02D89790u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BF0:
    // nop
    goto L_08B61BF4;
L_08B61BF4:
    // nop
    ctx.pc = 0x02D8A1C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61BF8:
    // nop
    goto L_08B61BFC;
L_08B61BFC:
    // nop
    ctx.pc = 0x02D8ABA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61C00:
    // nop
    goto L_08B61C04;
L_08B61C04:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(20), 0u);
    ctx.pc = 0x02D8B3E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B61C08:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(20), 0u);
    goto L_08B61C0C;
L_08B61C0C:
    jump_target = ctx.gpr[31];
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61C10:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), ctx.gpr[5]);
    goto L_08B61C14;
L_08B61C14:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B61C18;
L_08B61C18:
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B61C1C;
L_08B61C1C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B61C20;
L_08B61C20:
    { const bool branch_taken = ctx.gpr[6] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61C50;
      }
      goto L_08B61C28;
    }
L_08B61C24:
    // nop
    goto L_08B61C28;
L_08B61C28:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(20)));
    goto L_08B61C2C;
L_08B61C2C:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61C4C;
      }
      goto L_08B61C34;
    }
L_08B61C30:
    // nop
    goto L_08B61C34;
L_08B61C34:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    goto L_08B61C38;
L_08B61C38:
    ctx.gpr[4] = (ctx.gpr[6] | 0u);
    goto L_08B61C3C;
L_08B61C3C:
    ctx.gpr[31] = (0x08B61C44u);
    ctx.gpr[6] = (0u | 0u);
    ctx.pc = 0x0885C538u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61C44u) goto L_08B61C44;
    return;
L_08B61C40:
    ctx.gpr[6] = (0u | 0u);
    goto L_08B61C44;
L_08B61C44:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B61C48;
L_08B61C48:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(20), 0u);
    goto L_08B61C4C;
L_08B61C4C:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), 0u);
    goto L_08B61C50;
L_08B61C50:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B61C54;
L_08B61C54:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61C58:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B61C5C;
L_08B61C5C:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B61C60;
L_08B61C60:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(16), 0u);
    goto L_08B61C64;
L_08B61C64:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(12), 0u);
    goto L_08B61C68;
L_08B61C68:
    ctx.gpr[4] = (2205u << 16u);
    goto L_08B61C6C;
L_08B61C6C:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(19912)));
    goto L_08B61C70;
L_08B61C70:
    ctx.gpr[5] = (0u | 1u);
    goto L_08B61C74;
L_08B61C74:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B61C78;
L_08B61C78:
    ctx.gpr[31] = (0x08B61C80u);
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(29056));
    ctx.pc = 0x0885BA0Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61C80u) goto L_08B61C80;
    return;
L_08B61C7C:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(29056));
    goto L_08B61C80;
L_08B61C80:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B61C84;
L_08B61C84:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61C88:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B61C8C;
L_08B61C8C:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B61C90;
L_08B61C90:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B61C94;
L_08B61C94:
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
    goto L_08B61C98;
L_08B61C98:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B61C9C;
L_08B61C9C:
    ctx.gpr[31] = (0x08B61CA4u);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(16)));
    ctx.pc = 0x0899BB1Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61CA4u) goto L_08B61CA4;
    return;
L_08B61CA0:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(16)));
    goto L_08B61CA4;
L_08B61CA4:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(16), 0u);
    goto L_08B61CA8;
L_08B61CA8:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(12)));
    goto L_08B61CAC;
L_08B61CAC:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61CC0;
      }
      goto L_08B61CB4;
    }
L_08B61CB0:
    // nop
    goto L_08B61CB4;
L_08B61CB4:
    ctx.gpr[31] = (0x08B61CBCu);
    // nop
    ctx.pc = 0x0886EB84u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61CBCu) goto L_08B61CBC;
    return;
L_08B61CB8:
    // nop
    goto L_08B61CBC;
L_08B61CBC:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(12), 0u);
    goto L_08B61CC0;
L_08B61CC0:
    ctx.gpr[4] = (2205u << 16u);
    goto L_08B61CC4;
L_08B61CC4:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(19912)));
    goto L_08B61CC8;
L_08B61CC8:
    ctx.gpr[5] = (0u | 0u);
    goto L_08B61CCC;
L_08B61CCC:
    ctx.gpr[31] = (0x08B61CD4u);
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(29056));
    ctx.pc = 0x0885BA0Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61CD4u) goto L_08B61CD4;
    return;
L_08B61CD0:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(29056));
    goto L_08B61CD4;
L_08B61CD4:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B61CD8;
L_08B61CD8:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B61CDC;
L_08B61CDC:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61CE0:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B61CE4;
L_08B61CE4:
    jump_target = ctx.gpr[31];
    // nop
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61CE8:
    // nop
    goto L_08B61CEC;
L_08B61CEC:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B61CF0;
L_08B61CF0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B61CF4;
L_08B61CF4:
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
    goto L_08B61CF8;
L_08B61CF8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B61CFC;
L_08B61CFC:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B61D00;
L_08B61D00:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(144));
    goto L_08B61D04;
L_08B61D04:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[4] + static_cast<std::uint32_t>(0))))));
    goto L_08B61D08;
L_08B61D08:
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B61D0C;
L_08B61D0C:
    jump_target = ctx.gpr[6];
    ctx.gpr[31] = (0x08B61D14u);
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61D14u) goto L_08B61D14;
    return;
L_08B61D10:
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    goto L_08B61D14;
L_08B61D14:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B61D18;
L_08B61D18:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(176));
    goto L_08B61D1C;
L_08B61D1C:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[4] + static_cast<std::uint32_t>(0))))));
    goto L_08B61D20;
L_08B61D20:
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B61D24;
L_08B61D24:
    jump_target = ctx.gpr[6];
    ctx.gpr[31] = (0x08B61D2Cu);
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61D2Cu) goto L_08B61D2C;
    return;
L_08B61D28:
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    goto L_08B61D2C;
L_08B61D2C:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B61D30;
L_08B61D30:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B61D34;
L_08B61D34:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61D38:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B61D3C;
L_08B61D3C:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B61D40;
L_08B61D40:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[16]);
    goto L_08B61D44;
L_08B61D44:
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
    goto L_08B61D48;
L_08B61D48:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B61D4C;
L_08B61D4C:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(168));
    goto L_08B61D50;
L_08B61D50:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[4] + static_cast<std::uint32_t>(0))))));
    goto L_08B61D54;
L_08B61D54:
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B61D58;
L_08B61D58:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B61D5C;
L_08B61D5C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[31]);
    goto L_08B61D60;
L_08B61D60:
    jump_target = ctx.gpr[6];
    ctx.gpr[31] = (0x08B61D68u);
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61D68u) goto L_08B61D68;
    return;
L_08B61D64:
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    goto L_08B61D68;
L_08B61D68:
    ctx.fpr[20] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[0]));
    goto L_08B61D6C;
L_08B61D6C:
    ctx.fpr[12] = std::bit_cast<float>(0u);
    goto L_08B61D70;
L_08B61D70:
    ctx.set_fpu_condition((ctx.fpr[20] <= ctx.fpr[12]));
    goto L_08B61D74;
L_08B61D74:
    // nop
    goto L_08B61D78;
L_08B61D78:
    { const bool branch_taken = ctx.fpu_condition();
    // nop
      if (branch_taken) {
          goto L_08B61DB8;
      }
      goto L_08B61D80;
    }
L_08B61D7C:
    // nop
    goto L_08B61D80;
L_08B61D80:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B61D84;
L_08B61D84:
    ctx.fpr[12] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B61D88;
L_08B61D88:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(152));
    goto L_08B61D8C;
L_08B61D8C:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[4] + static_cast<std::uint32_t>(0))))));
    goto L_08B61D90;
L_08B61D90:
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B61D94;
L_08B61D94:
    jump_target = ctx.gpr[6];
    ctx.gpr[31] = (0x08B61D9Cu);
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61D9Cu) goto L_08B61D9C;
    return;
L_08B61D98:
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    goto L_08B61D9C;
L_08B61D9C:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B61DA0;
L_08B61DA0:
    ctx.fpr[12] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B61DA4;
L_08B61DA4:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(160));
    goto L_08B61DA8;
L_08B61DA8:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[4] + static_cast<std::uint32_t>(0))))));
    goto L_08B61DAC;
L_08B61DAC:
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B61DB0;
L_08B61DB0:
    jump_target = ctx.gpr[6];
    ctx.gpr[31] = (0x08B61DB8u);
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61DB8u) goto L_08B61DB8;
    return;
L_08B61DB4:
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    goto L_08B61DB8;
L_08B61DB8:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B61DBC;
L_08B61DBC:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B61DC0;
L_08B61DC0:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08B61DC4;
L_08B61DC4:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61DC8:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B61DCC;
L_08B61DCC:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B61DD0;
L_08B61DD0:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B61DD4;
L_08B61DD4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B61DD8;
L_08B61DD8:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61E18;
      }
      goto L_08B61DE0;
    }
L_08B61DDC:
    // nop
    goto L_08B61DE0;
L_08B61DE0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    goto L_08B61DE4;
L_08B61DE4:
    ctx.gpr[4] = (ctx.gpr[5] | 0u);
    goto L_08B61DE8;
L_08B61DE8:
    ctx.gpr[8] = (0u | 1u);
    goto L_08B61DEC;
L_08B61DEC:
    ctx.gpr[5] = (0u | 2560u);
    goto L_08B61DF0;
L_08B61DF0:
    ctx.gpr[6] = (0u | 0u);
    goto L_08B61DF4;
L_08B61DF4:
    ctx.gpr[7] = (0u | 0u);
    goto L_08B61DF8;
L_08B61DF8:
    ctx.gpr[31] = (0x08B61E00u);
    ctx.gpr[9] = (0u | 0u);
    ctx.pc = 0x0885C6CCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61E00u) goto L_08B61E00;
    return;
L_08B61DFC:
    ctx.gpr[9] = (0u | 0u);
    goto L_08B61E00;
L_08B61E00:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B61E04;
L_08B61E04:
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
    goto L_08B61E08;
L_08B61E08:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(20), ctx.gpr[2]);
      if (branch_taken) {
          goto L_08B61E20;
      }
      goto L_08B61E10;
    }
L_08B61E0C:
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(20), ctx.gpr[2]);
    goto L_08B61E10;
L_08B61E10:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61E44;
      }
      goto L_08B61E18;
    }
L_08B61E14:
    // nop
    goto L_08B61E18;
L_08B61E18:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61E44;
      }
      goto L_08B61E20;
    }
L_08B61E1C:
    // nop
    goto L_08B61E20;
L_08B61E20:
    ctx.gpr[5] = (ctx.gpr[4] | 0u);
    goto L_08B61E24;
L_08B61E24:
    ctx.fpr[12] = std::bit_cast<float>(0u);
    goto L_08B61E28;
L_08B61E28:
    ctx.gpr[4] = (0u | 0u);
    goto L_08B61E2C;
L_08B61E2C:
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(24), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61E30;
L_08B61E30:
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(28), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61E34;
L_08B61E34:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(1));
    goto L_08B61E38;
L_08B61E38:
    ctx.gpr[6] = (static_cast<std::int32_t>(ctx.gpr[4]) < 80 ? 1u : 0u);
    goto L_08B61E3C;
L_08B61E3C:
    { const bool branch_taken = ctx.gpr[6] != 0u;
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(32));
      if (branch_taken) {
          goto L_08B61E2C;
      }
      goto L_08B61E44;
    }
L_08B61E40:
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(32));
    goto L_08B61E44;
L_08B61E44:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B61E48;
L_08B61E48:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61E4C:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B61E50;
L_08B61E50:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B61E54;
L_08B61E54:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B61E58;
L_08B61E58:
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
    goto L_08B61E5C;
L_08B61E5C:
    ctx.gpr[4] = (ctx.gpr[5] | 0u);
    goto L_08B61E60;
L_08B61E60:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B61E64;
L_08B61E64:
    ctx.gpr[31] = (0x08B61E6Cu);
    ctx.gpr[5] = (ctx.gpr[6] | 0u);
    ctx.pc = 0x08869AB4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61E6Cu) goto L_08B61E6C;
    return;
L_08B61E68:
    ctx.gpr[5] = (ctx.gpr[6] | 0u);
    goto L_08B61E6C;
L_08B61E6C:
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
    goto L_08B61E70;
L_08B61E70:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    // nop
      if (branch_taken) {
          goto L_08B61E80;
      }
      goto L_08B61E78;
    }
L_08B61E74:
    // nop
    goto L_08B61E78;
L_08B61E78:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61E90;
      }
      goto L_08B61E80;
    }
L_08B61E7C:
    // nop
    goto L_08B61E80;
L_08B61E80:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(8)));
    goto L_08B61E84;
L_08B61E84:
    ctx.gpr[31] = (0x08B61E8Cu);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    ctx.pc = 0x08B52F88u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61E8Cu) goto L_08B61E8C;
    return;
L_08B61E88:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B61E8C;
L_08B61E8C:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(16), ctx.gpr[2]);
    goto L_08B61E90;
L_08B61E90:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B61E94;
L_08B61E94:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B61E98;
L_08B61E98:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61E9C:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B61EA0;
L_08B61EA0:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B61EA4;
L_08B61EA4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B61EA8;
L_08B61EA8:
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
    goto L_08B61EAC;
L_08B61EAC:
    ctx.gpr[4] = (ctx.gpr[5] | 0u);
    goto L_08B61EB0;
L_08B61EB0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B61EB4;
L_08B61EB4:
    ctx.gpr[31] = (0x08B61EBCu);
    ctx.gpr[5] = (ctx.gpr[6] | 0u);
    ctx.pc = 0x08869AB4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61EBCu) goto L_08B61EBC;
    return;
L_08B61EB8:
    ctx.gpr[5] = (ctx.gpr[6] | 0u);
    goto L_08B61EBC;
L_08B61EBC:
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
    goto L_08B61EC0;
L_08B61EC0:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61F08;
      }
      goto L_08B61EC8;
    }
L_08B61EC4:
    // nop
    goto L_08B61EC8;
L_08B61EC8:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B61ECC;
L_08B61ECC:
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(8)));
    goto L_08B61ED0;
L_08B61ED0:
    ctx.gpr[4] = (2230u << 16u);
    goto L_08B61ED4;
L_08B61ED4:
    ctx.gpr[31] = (0x08B61EDCu);
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(12032));
    ctx.pc = 0x0886D2C4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61EDCu) goto L_08B61EDC;
    return;
L_08B61ED8:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(12032));
    goto L_08B61EDC;
L_08B61EDC:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(12), ctx.gpr[2]);
    goto L_08B61EE0;
L_08B61EE0:
    ctx.gpr[16] = (ctx.gpr[2] | 0u);
    goto L_08B61EE4;
L_08B61EE4:
    { const bool branch_taken = ctx.gpr[16] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61F00;
      }
      goto L_08B61EEC;
    }
L_08B61EE8:
    // nop
    goto L_08B61EEC;
L_08B61EEC:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(12)));
    goto L_08B61EF0;
L_08B61EF0:
    { const bool branch_taken = ctx.gpr[16] != 0u;
    // nop
      if (branch_taken) {
          goto L_08B61F10;
      }
      goto L_08B61EF8;
    }
L_08B61EF4:
    // nop
    goto L_08B61EF8;
L_08B61EF8:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61F20;
      }
      goto L_08B61F00;
    }
L_08B61EFC:
    // nop
    goto L_08B61F00;
L_08B61F00:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61F20;
      }
      goto L_08B61F08;
    }
L_08B61F04:
    // nop
    goto L_08B61F08;
L_08B61F08:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B61F20;
      }
      goto L_08B61F10;
    }
L_08B61F0C:
    // nop
    goto L_08B61F10;
L_08B61F10:
    ctx.gpr[4] = (ctx.gpr[16] | 0u);
    goto L_08B61F14;
L_08B61F14:
    ctx.gpr[5] = (0u | 32u);
    goto L_08B61F18;
L_08B61F18:
    ctx.gpr[31] = (0x08B61F20u);
    ctx.gpr[6] = (0u | 0u);
    ctx.pc = 0x089B0D40u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61F20u) goto L_08B61F20;
    return;
L_08B61F1C:
    ctx.gpr[6] = (0u | 0u);
    goto L_08B61F20;
L_08B61F20:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B61F24;
L_08B61F24:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B61F28;
L_08B61F28:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B61F2C:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B61F30;
L_08B61F30:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-144));
    goto L_08B61F34;
L_08B61F34:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(20)));
    goto L_08B61F38;
L_08B61F38:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(80), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B61F3C;
L_08B61F3C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(84), std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B61F40;
L_08B61F40:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(88), std::bit_cast<std::uint32_t>(ctx.fpr[24]));
    goto L_08B61F44;
L_08B61F44:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(92), ctx.gpr[16]);
    goto L_08B61F48;
L_08B61F48:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(96), ctx.gpr[17]);
    goto L_08B61F4C;
L_08B61F4C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(100), ctx.gpr[18]);
    goto L_08B61F50;
L_08B61F50:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(104), ctx.gpr[19]);
    goto L_08B61F54;
L_08B61F54:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(108), ctx.gpr[20]);
    goto L_08B61F58;
L_08B61F58:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(112), ctx.gpr[21]);
    goto L_08B61F5C;
L_08B61F5C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(116), ctx.gpr[22]);
    goto L_08B61F60;
L_08B61F60:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(120), ctx.gpr[23]);
    goto L_08B61F64;
L_08B61F64:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(124), ctx.gpr[30]);
    goto L_08B61F68;
L_08B61F68:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(128), ctx.gpr[31]);
    goto L_08B61F6C;
L_08B61F6C:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(76), ctx.gpr[4]);
      if (branch_taken) {
          goto L_08B61F7C;
      }
      goto L_08B61F74;
    }
L_08B61F70:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(76), ctx.gpr[4]);
    goto L_08B61F74;
L_08B61F74:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B622D8;
      }
      goto L_08B61F7C;
    }
L_08B61F78:
    // nop
    goto L_08B61F7C;
L_08B61F7C:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(76)));
    goto L_08B61F80;
L_08B61F80:
    ctx.gpr[4] = (ctx.gpr[29] + static_cast<std::uint32_t>(32));
    goto L_08B61F84;
L_08B61F84:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B61F88;
L_08B61F88:
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(184));
    goto L_08B61F8C;
L_08B61F8C:
    ctx.gpr[6] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[5] + static_cast<std::uint32_t>(0))))));
    goto L_08B61F90;
L_08B61F90:
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    goto L_08B61F94;
L_08B61F94:
    jump_target = ctx.gpr[7];
    ctx.gpr[31] = (0x08B61F9Cu);
    ctx.gpr[5] = (ctx.gpr[16] + ctx.gpr[6]);
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B61F9Cu) goto L_08B61F9C;
    return;
L_08B61F98:
    ctx.gpr[5] = (ctx.gpr[16] + ctx.gpr[6]);
    goto L_08B61F9C;
L_08B61F9C:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(32)));
    goto L_08B61FA0;
L_08B61FA0:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(36)));
    goto L_08B61FA4;
L_08B61FA4:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61FA8;
L_08B61FA8:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(40)));
    goto L_08B61FAC;
L_08B61FAC:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B61FB0;
L_08B61FB0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    goto L_08B61FB4;
L_08B61FB4:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B61FB8;
L_08B61FB8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[5]);
    goto L_08B61FBC;
L_08B61FBC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[4]);
    goto L_08B61FC0;
L_08B61FC0:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(44)));
    goto L_08B61FC4;
L_08B61FC4:
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B61FC8;
L_08B61FC8:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[15]));
    goto L_08B61FCC;
L_08B61FCC:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B61FD0;
L_08B61FD0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[4]);
    goto L_08B61FD4;
L_08B61FD4:
    ctx.fpr[24] = std::bit_cast<float>(0u);
    goto L_08B61FD8;
L_08B61FD8:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    goto L_08B61FDC;
L_08B61FDC:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08B61FE0;
L_08B61FE0:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B61FE4;
L_08B61FE4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[4]);
    goto L_08B61FE8;
L_08B61FE8:
    ctx.gpr[7] = (std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B61FEC;
L_08B61FEC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[5]);
    goto L_08B61FF0;
L_08B61FF0:
    ctx.gpr[6] = (2205u << 16u);
    goto L_08B61FF4;
L_08B61FF4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[7]);
    goto L_08B61FF8;
L_08B61FF8:
    ctx.gpr[4] = (14336u << 16u);
    goto L_08B61FFC;
L_08B61FFC:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(24236)));
    goto L_08B62000;
L_08B62000:
    ctx.gpr[4] = (ctx.gpr[4] | 256u);
    goto L_08B62004;
L_08B62004:
    ctx.gpr[19] = (3u << 16u);
    goto L_08B62008;
L_08B62008:
    ctx.fpr[22] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B6200C;
L_08B6200C:
    ctx.gpr[18] = (39u << 16u);
    goto L_08B62010;
L_08B62010:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(20)));
    goto L_08B62014;
L_08B62014:
    ctx.gpr[20] = (0u | 0u);
    goto L_08B62018;
L_08B62018:
    ctx.gpr[21] = (ctx.gpr[29] + static_cast<std::uint32_t>(48));
    goto L_08B6201C;
L_08B6201C:
    ctx.gpr[19] = (ctx.gpr[19] + static_cast<std::uint32_t>(17405));
    goto L_08B62020;
L_08B62020:
    ctx.gpr[18] = (ctx.gpr[18] + static_cast<std::uint32_t>(-24893));
    goto L_08B62024;
L_08B62024:
    ctx.gpr[17] = (2480u << 16u);
    goto L_08B62028;
L_08B62028:
    ctx.gpr[30] = (2230u << 16u);
    goto L_08B6202C;
L_08B6202C:
    ctx.gpr[23] = (2230u << 16u);
    goto L_08B62030;
L_08B62030:
    ctx.gpr[22] = (2230u << 16u);
    goto L_08B62034;
L_08B62034:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(28)));
    goto L_08B62038;
L_08B62038:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(24)));
    goto L_08B6203C;
L_08B6203C:
    ctx.fpr[12] = ctx.fpr[12] + ctx.fpr[20];
    goto L_08B62040;
L_08B62040:
    ctx.gpr[4] = (ctx.gpr[16] + static_cast<std::uint32_t>(12));
    goto L_08B62044;
L_08B62044:
    ctx.set_fpu_condition((ctx.fpr[13] <= ctx.fpr[12]));
    goto L_08B62048;
L_08B62048:
    // nop
    goto L_08B6204C;
L_08B6204C:
    { const bool branch_taken = !ctx.fpu_condition();
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(28), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
      if (branch_taken) {
          goto L_08B622A4;
      }
      goto L_08B62054;
    }
L_08B62050:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(28), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62054;
L_08B62054:
    ctx.gpr[5] = (2230u << 16u);
    goto L_08B62058;
L_08B62058:
    ctx.gpr[6] = (2230u << 16u);
    goto L_08B6205C;
L_08B6205C:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(11980)));
    goto L_08B62060;
L_08B62060:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(11984)));
    goto L_08B62064;
L_08B62064:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276)));
    goto L_08B62068;
L_08B62068:
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[5])) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[19])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    goto L_08B6206C;
L_08B6206C:
    ctx.gpr[5] = (ctx.lo);
    goto L_08B62070;
L_08B62070:
    ctx.gpr[5] = (ctx.gpr[5] + ctx.gpr[18]);
    goto L_08B62074;
L_08B62074:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276), ctx.gpr[5]);
    goto L_08B62078;
L_08B62078:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[5]) >> 16u));
    goto L_08B6207C;
L_08B6207C:
    ctx.gpr[5] = (ctx.gpr[5] & 32767u);
    goto L_08B62080;
L_08B62080:
    ctx.fpr[14] = std::bit_cast<float>(ctx.gpr[5]);
    goto L_08B62084;
L_08B62084:
    ctx.fpr[14] = static_cast<float>(static_cast<std::int32_t>(std::bit_cast<std::uint32_t>(ctx.fpr[14])));
    goto L_08B62088;
L_08B62088:
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    goto L_08B6208C;
L_08B6208C:
    ctx.fpr[13] = ctx.fpr[13] - ctx.fpr[12];
    goto L_08B62090;
L_08B62090:
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B62094;
L_08B62094:
    ctx.fpr[12] = ctx.fpr[13] + ctx.fpr[12];
    goto L_08B62098;
L_08B62098:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(16)));
    goto L_08B6209C;
L_08B6209C:
    ctx.fpr[12] = ctx.fpr[15] + ctx.fpr[12];
    goto L_08B620A0;
L_08B620A0:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B620A4;
L_08B620A4:
    ctx.gpr[5] = (2230u << 16u);
    goto L_08B620A8;
L_08B620A8:
    ctx.gpr[6] = (2230u << 16u);
    goto L_08B620AC;
L_08B620AC:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(11988)));
    goto L_08B620B0;
L_08B620B0:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(11992)));
    goto L_08B620B4;
L_08B620B4:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276)));
    goto L_08B620B8;
L_08B620B8:
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[5])) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[19])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    goto L_08B620BC;
L_08B620BC:
    ctx.gpr[5] = (ctx.lo);
    goto L_08B620C0;
L_08B620C0:
    ctx.gpr[5] = (ctx.gpr[5] + ctx.gpr[18]);
    goto L_08B620C4;
L_08B620C4:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276), ctx.gpr[5]);
    goto L_08B620C8;
L_08B620C8:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[5]) >> 16u));
    goto L_08B620CC;
L_08B620CC:
    ctx.gpr[5] = (ctx.gpr[5] & 32767u);
    goto L_08B620D0;
L_08B620D0:
    ctx.fpr[13] = std::bit_cast<float>(ctx.gpr[5]);
    goto L_08B620D4;
L_08B620D4:
    ctx.fpr[13] = static_cast<float>(static_cast<std::int32_t>(std::bit_cast<std::uint32_t>(ctx.fpr[13])));
    goto L_08B620D8;
L_08B620D8:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B620DC;
L_08B620DC:
    ctx.fpr[14] = ctx.fpr[14] - ctx.fpr[12];
    goto L_08B620E0;
L_08B620E0:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B620E4;
L_08B620E4:
    ctx.fpr[12] = ctx.fpr[13] + ctx.fpr[12];
    goto L_08B620E8;
L_08B620E8:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(20)));
    goto L_08B620EC;
L_08B620EC:
    ctx.fpr[12] = ctx.fpr[15] + ctx.fpr[12];
    goto L_08B620F0;
L_08B620F0:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B620F4;
L_08B620F4:
    ctx.gpr[5] = (2230u << 16u);
    goto L_08B620F8;
L_08B620F8:
    ctx.gpr[6] = (2230u << 16u);
    goto L_08B620FC;
L_08B620FC:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(11996)));
    goto L_08B62100;
L_08B62100:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(12000)));
    goto L_08B62104;
L_08B62104:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276)));
    goto L_08B62108;
L_08B62108:
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[5])) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[19])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    goto L_08B6210C;
L_08B6210C:
    ctx.gpr[5] = (ctx.lo);
    goto L_08B62110;
L_08B62110:
    ctx.gpr[5] = (ctx.gpr[5] + ctx.gpr[18]);
    goto L_08B62114;
L_08B62114:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276), ctx.gpr[5]);
    goto L_08B62118;
L_08B62118:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[5]) >> 16u));
    goto L_08B6211C;
L_08B6211C:
    ctx.gpr[5] = (ctx.gpr[5] & 32767u);
    goto L_08B62120;
L_08B62120:
    ctx.fpr[13] = std::bit_cast<float>(ctx.gpr[5]);
    goto L_08B62124;
L_08B62124:
    ctx.fpr[13] = static_cast<float>(static_cast<std::int32_t>(std::bit_cast<std::uint32_t>(ctx.fpr[13])));
    goto L_08B62128;
L_08B62128:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B6212C;
L_08B6212C:
    ctx.fpr[14] = ctx.fpr[14] - ctx.fpr[12];
    goto L_08B62130;
L_08B62130:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B62134;
L_08B62134:
    ctx.fpr[12] = ctx.fpr[13] + ctx.fpr[12];
    goto L_08B62138;
L_08B62138:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(24)));
    goto L_08B6213C;
L_08B6213C:
    ctx.fpr[12] = ctx.fpr[15] + ctx.fpr[12];
    goto L_08B62140;
L_08B62140:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62144;
L_08B62144:
    ctx.gpr[5] = (2230u << 16u);
    goto L_08B62148;
L_08B62148:
    ctx.gpr[6] = (2230u << 16u);
    goto L_08B6214C;
L_08B6214C:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(12004)));
    goto L_08B62150;
L_08B62150:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(12008)));
    goto L_08B62154;
L_08B62154:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276)));
    goto L_08B62158;
L_08B62158:
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[5])) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[19])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    goto L_08B6215C;
L_08B6215C:
    ctx.gpr[5] = (ctx.lo);
    goto L_08B62160;
L_08B62160:
    ctx.gpr[5] = (ctx.gpr[5] + ctx.gpr[18]);
    goto L_08B62164;
L_08B62164:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276), ctx.gpr[5]);
    goto L_08B62168;
L_08B62168:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[5]) >> 16u));
    goto L_08B6216C;
L_08B6216C:
    ctx.gpr[5] = (ctx.gpr[5] & 32767u);
    goto L_08B62170;
L_08B62170:
    ctx.fpr[13] = std::bit_cast<float>(ctx.gpr[5]);
    goto L_08B62174;
L_08B62174:
    ctx.fpr[13] = static_cast<float>(static_cast<std::int32_t>(std::bit_cast<std::uint32_t>(ctx.fpr[13])));
    goto L_08B62178;
L_08B62178:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B6217C;
L_08B6217C:
    ctx.fpr[14] = ctx.fpr[14] - ctx.fpr[12];
    goto L_08B62180;
L_08B62180:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B62184;
L_08B62184:
    ctx.fpr[12] = ctx.fpr[13] + ctx.fpr[12];
    goto L_08B62188;
L_08B62188:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B6218C;
L_08B6218C:
    ctx.gpr[5] = (2230u << 16u);
    goto L_08B62190;
L_08B62190:
    ctx.gpr[6] = (2230u << 16u);
    goto L_08B62194;
L_08B62194:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(12012)));
    goto L_08B62198;
L_08B62198:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(12016)));
    goto L_08B6219C;
L_08B6219C:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276)));
    goto L_08B621A0;
L_08B621A0:
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[5])) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[19])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    goto L_08B621A4;
L_08B621A4:
    ctx.gpr[5] = (ctx.lo);
    goto L_08B621A8;
L_08B621A8:
    ctx.gpr[5] = (ctx.gpr[5] + ctx.gpr[18]);
    goto L_08B621AC;
L_08B621AC:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276), ctx.gpr[5]);
    goto L_08B621B0;
L_08B621B0:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[5]) >> 16u));
    goto L_08B621B4;
L_08B621B4:
    ctx.gpr[5] = (ctx.gpr[5] & 32767u);
    goto L_08B621B8;
L_08B621B8:
    ctx.fpr[13] = std::bit_cast<float>(ctx.gpr[5]);
    goto L_08B621BC;
L_08B621BC:
    ctx.fpr[13] = static_cast<float>(static_cast<std::int32_t>(std::bit_cast<std::uint32_t>(ctx.fpr[13])));
    goto L_08B621C0;
L_08B621C0:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B621C4;
L_08B621C4:
    ctx.fpr[14] = ctx.fpr[15] - ctx.fpr[12];
    goto L_08B621C8;
L_08B621C8:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B621CC;
L_08B621CC:
    ctx.fpr[12] = ctx.fpr[13] + ctx.fpr[12];
    goto L_08B621D0;
L_08B621D0:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(16), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B621D4;
L_08B621D4:
    ctx.gpr[5] = (2230u << 16u);
    goto L_08B621D8;
L_08B621D8:
    ctx.gpr[6] = (2230u << 16u);
    goto L_08B621DC;
L_08B621DC:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(12020)));
    goto L_08B621E0;
L_08B621E0:
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(12024)));
    goto L_08B621E4;
L_08B621E4:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276)));
    goto L_08B621E8;
L_08B621E8:
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[5])) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[19])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    goto L_08B621EC;
L_08B621EC:
    ctx.gpr[5] = (ctx.lo);
    goto L_08B621F0;
L_08B621F0:
    ctx.gpr[5] = (ctx.gpr[5] + ctx.gpr[18]);
    goto L_08B621F4;
L_08B621F4:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276), ctx.gpr[5]);
    goto L_08B621F8;
L_08B621F8:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[5]) >> 16u));
    goto L_08B621FC;
L_08B621FC:
    ctx.gpr[5] = (ctx.gpr[5] & 32767u);
    goto L_08B62200;
L_08B62200:
    ctx.fpr[13] = std::bit_cast<float>(ctx.gpr[5]);
    goto L_08B62204;
L_08B62204:
    ctx.fpr[13] = static_cast<float>(static_cast<std::int32_t>(std::bit_cast<std::uint32_t>(ctx.fpr[13])));
    goto L_08B62208;
L_08B62208:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B6220C;
L_08B6220C:
    ctx.fpr[14] = ctx.fpr[16] - ctx.fpr[12];
    goto L_08B62210;
L_08B62210:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B62214;
L_08B62214:
    ctx.fpr[12] = ctx.fpr[13] + ctx.fpr[12];
    goto L_08B62218;
L_08B62218:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(20), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B6221C;
L_08B6221C:
    ctx.set_vfpu_scalar_bits_ct<0u>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    goto L_08B62220;
L_08B62220:
    ctx.set_vfpu_scalar_bits_ct<32u>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B62224;
L_08B62224:
    ctx.set_vfpu_scalar_bits_ct<64u>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(8)));
    goto L_08B62228;
L_08B62228:
    ctx.execute_vfpu_vdot_ct<1u, 0u, 0u, 3u>();
    goto L_08B6222C;
L_08B6222C:
    { float vfpu_value[4]{};
      ctx.write_vfpu_vector_with_destination_prefix_ct<33u, 1u>(vfpu_value); }
    goto L_08B62230;
L_08B62230:
    ctx.execute_vfpu_vcmp_ct<1u, 0u, 1u, 8u>();
    goto L_08B62234;
L_08B62234:
    { float vfpu_s[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<1u, 1u, 0u>(vfpu_s);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = std::fabs(std::sqrt(vfpu_s[i]));
      ctx.write_vfpu_vector_with_destination_prefix_ct<1u, 1u>(vfpu_d); }
    goto L_08B62238;
L_08B62238:
    ctx.gpr[5] = (ctx.gpr[29] + static_cast<std::uint32_t>(72));
    goto L_08B6223C;
L_08B6223C:
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(0), ctx.vfpu_scalar_bits_ct<1u>());
    goto L_08B62240;
L_08B62240:
    { float vfpu_s[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<1u, 1u, 0u>(vfpu_s);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = 1.0f / vfpu_s[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<1u, 1u>(vfpu_d); }
    goto L_08B62244;
L_08B62244:
    ctx.execute_vfpu_vcmov_ct<1u, 33u, 1u, 0u, false>();
    goto L_08B62248;
L_08B62248:
    ctx.vfpu_ctrl[2u] = 0x0000083Fu;
    goto L_08B6224C;
L_08B6224C:
    ctx.execute_vfpu_vscl_ct<0u, 0u, 1u, 3u>();
    goto L_08B62250;
L_08B62250:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), ctx.vfpu_scalar_bits_ct<0u>());
    goto L_08B62254;
L_08B62254:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), ctx.vfpu_scalar_bits_ct<32u>());
    goto L_08B62258;
L_08B62258:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(8), ctx.vfpu_scalar_bits_ct<64u>());
    goto L_08B6225C;
L_08B6225C:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[30] + static_cast<std::uint32_t>(11972)));
    goto L_08B62260;
L_08B62260:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[23] + static_cast<std::uint32_t>(11976)));
    goto L_08B62264;
L_08B62264:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276)));
    goto L_08B62268;
L_08B62268:
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[4])) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[19])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    goto L_08B6226C;
L_08B6226C:
    ctx.gpr[4] = (ctx.lo);
    goto L_08B62270;
L_08B62270:
    ctx.gpr[4] = (ctx.gpr[4] + ctx.gpr[18]);
    goto L_08B62274;
L_08B62274:
    aot_mem.aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(-18276), ctx.gpr[4]);
    goto L_08B62278;
L_08B62278:
    ctx.gpr[4] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[4]) >> 16u));
    goto L_08B6227C;
L_08B6227C:
    ctx.gpr[4] = (ctx.gpr[4] & 32767u);
    goto L_08B62280;
L_08B62280:
    ctx.fpr[14] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B62284;
L_08B62284:
    ctx.fpr[14] = static_cast<float>(static_cast<std::int32_t>(std::bit_cast<std::uint32_t>(ctx.fpr[14])));
    goto L_08B62288;
L_08B62288:
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    goto L_08B6228C;
L_08B6228C:
    ctx.fpr[13] = ctx.fpr[13] - ctx.fpr[12];
    goto L_08B62290;
L_08B62290:
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B62294;
L_08B62294:
    ctx.fpr[12] = ctx.fpr[13] + ctx.fpr[12];
    goto L_08B62298;
L_08B62298:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(24), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B6229C;
L_08B6229C:
    { const bool branch_taken = 0u == 0u;
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(28), std::bit_cast<std::uint32_t>(ctx.fpr[24]));
      if (branch_taken) {
          goto L_08B622C8;
      }
      goto L_08B622A4;
    }
L_08B622A0:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(28), std::bit_cast<std::uint32_t>(ctx.fpr[24]));
    goto L_08B622A4;
L_08B622A4:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[22] + static_cast<std::uint32_t>(11968)));
    goto L_08B622A8;
L_08B622A8:
    ctx.gpr[5] = (ctx.gpr[4] | 0u);
    goto L_08B622AC;
L_08B622AC:
    ctx.gpr[4] = (ctx.gpr[21] | 0u);
    goto L_08B622B0;
L_08B622B0:
    ctx.gpr[31] = (0x08B622B8u);
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[20]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    ctx.pc = 0x089A3680u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B622B8u) goto L_08B622B8;
    return;
L_08B622B4:
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[20]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B622B8;
L_08B622B8:
    ctx.gpr[4] = (ctx.gpr[16] | 0u);
    goto L_08B622BC;
L_08B622BC:
    ctx.gpr[5] = (ctx.gpr[16] | 0u);
    goto L_08B622C0;
L_08B622C0:
    ctx.gpr[31] = (0x08B622C8u);
    ctx.gpr[6] = (ctx.gpr[21] | 0u);
    ctx.pc = 0x089A34F4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B622C8u) goto L_08B622C8;
    return;
L_08B622C4:
    ctx.gpr[6] = (ctx.gpr[21] | 0u);
    goto L_08B622C8;
L_08B622C8:
    ctx.gpr[20] = (ctx.gpr[20] + static_cast<std::uint32_t>(1));
    goto L_08B622CC;
L_08B622CC:
    ctx.gpr[4] = (static_cast<std::int32_t>(ctx.gpr[20]) < 80 ? 1u : 0u);
    goto L_08B622D0;
L_08B622D0:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.gpr[16] = (ctx.gpr[16] + static_cast<std::uint32_t>(32));
      if (branch_taken) {
          goto L_08B62034;
      }
      goto L_08B622D8;
    }
L_08B622D4:
    ctx.gpr[16] = (ctx.gpr[16] + static_cast<std::uint32_t>(32));
    goto L_08B622D8;
L_08B622D8:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(80)));
    goto L_08B622DC;
L_08B622DC:
    ctx.fpr[22] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(84)));
    goto L_08B622E0;
L_08B622E0:
    ctx.fpr[24] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(88)));
    goto L_08B622E4;
L_08B622E4:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(92)));
    goto L_08B622E8;
L_08B622E8:
    ctx.gpr[17] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(96)));
    goto L_08B622EC;
L_08B622EC:
    ctx.gpr[18] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(100)));
    goto L_08B622F0;
L_08B622F0:
    ctx.gpr[19] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(104)));
    goto L_08B622F4;
L_08B622F4:
    ctx.gpr[20] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(108)));
    goto L_08B622F8;
L_08B622F8:
    ctx.gpr[21] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(112)));
    goto L_08B622FC;
L_08B622FC:
    ctx.gpr[22] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(116)));
    goto L_08B62300;
L_08B62300:
    ctx.gpr[23] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(120)));
    goto L_08B62304;
L_08B62304:
    ctx.gpr[30] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(124)));
    goto L_08B62308;
L_08B62308:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(128)));
    goto L_08B6230C;
L_08B6230C:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(144));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B62310:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(144));
    goto L_08B62314;
L_08B62314:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-96));
    goto L_08B62318;
L_08B62318:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(20)));
    goto L_08B6231C;
L_08B6231C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(32), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B62320;
L_08B62320:
    ctx.fpr[20] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62324;
L_08B62324:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(36), std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B62328;
L_08B62328:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(40), std::bit_cast<std::uint32_t>(ctx.fpr[24]));
    goto L_08B6232C;
L_08B6232C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(44), std::bit_cast<std::uint32_t>(ctx.fpr[26]));
    goto L_08B62330;
L_08B62330:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(48), ctx.gpr[16]);
    goto L_08B62334;
L_08B62334:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(52), ctx.gpr[17]);
    goto L_08B62338;
L_08B62338:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(56), ctx.gpr[18]);
    goto L_08B6233C;
L_08B6233C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(60), ctx.gpr[19]);
    goto L_08B62340;
L_08B62340:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(64), ctx.gpr[20]);
    goto L_08B62344;
L_08B62344:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(68), ctx.gpr[21]);
    goto L_08B62348;
L_08B62348:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(72), ctx.gpr[22]);
    goto L_08B6234C;
L_08B6234C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(76), ctx.gpr[23]);
    goto L_08B62350;
L_08B62350:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(80), ctx.gpr[30]);
    goto L_08B62354;
L_08B62354:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(84), ctx.gpr[31]);
    goto L_08B62358;
L_08B62358:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
      if (branch_taken) {
          goto L_08B6237C;
      }
      goto L_08B62360;
    }
L_08B6235C:
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
    goto L_08B62360;
L_08B62360:
    ctx.gpr[31] = (0x08B62368u);
    ctx.gpr[4] = (0u | 3840u);
    ctx.pc = 0x0885CD44u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62368u) goto L_08B62368;
    return;
L_08B62364:
    ctx.gpr[4] = (0u | 3840u);
    goto L_08B62368;
L_08B62368:
    ctx.gpr[17] = (ctx.gpr[2] | 0u);
    goto L_08B6236C;
L_08B6236C:
    { const bool branch_taken = ctx.gpr[17] != 0u;
    // nop
      if (branch_taken) {
          goto L_08B62384;
      }
      goto L_08B62374;
    }
L_08B62370:
    // nop
    goto L_08B62374;
L_08B62374:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B625A4;
      }
      goto L_08B6237C;
    }
L_08B62378:
    // nop
    goto L_08B6237C;
L_08B6237C:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B625A4;
      }
      goto L_08B62384;
    }
L_08B62380:
    // nop
    goto L_08B62384;
L_08B62384:
    ctx.gpr[4] = (2205u << 16u);
    goto L_08B62388;
L_08B62388:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(24256)));
    goto L_08B6238C;
L_08B6238C:
    ctx.gpr[4] = (2230u << 16u);
    goto L_08B62390;
L_08B62390:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(11964)));
    goto L_08B62394;
L_08B62394:
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(2000));
    goto L_08B62398;
L_08B62398:
    ctx.gpr[31] = (0x08B623A0u);
    ctx.gpr[4] = (ctx.gpr[29] | 0u);
    ctx.pc = 0x089A3A44u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B623A0u) goto L_08B623A0;
    return;
L_08B6239C:
    ctx.gpr[4] = (ctx.gpr[29] | 0u);
    goto L_08B623A0;
L_08B623A0:
    ctx.gpr[4] = (17279u << 16u);
    goto L_08B623A4;
L_08B623A4:
    ctx.fpr[22] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B623A8;
L_08B623A8:
    ctx.gpr[23] = (256u << 16u);
    goto L_08B623AC;
L_08B623AC:
    ctx.gpr[4] = (20224u << 16u);
    goto L_08B623B0;
L_08B623B0:
    ctx.fpr[24] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B623B4;
L_08B623B4:
    ctx.gpr[18] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(20)));
    goto L_08B623B8;
L_08B623B8:
    ctx.gpr[4] = (16256u << 16u);
    goto L_08B623BC;
L_08B623BC:
    ctx.gpr[19] = (ctx.gpr[17] | 0u);
    goto L_08B623C0;
L_08B623C0:
    ctx.fpr[26] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B623C4;
L_08B623C4:
    ctx.gpr[20] = (0u | 0u);
    goto L_08B623C8;
L_08B623C8:
    ctx.gpr[30] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B623CC;
L_08B623CC:
    ctx.gpr[23] = (ctx.gpr[23] + static_cast<std::uint32_t>(-1));
    goto L_08B623D0;
L_08B623D0:
    ctx.gpr[21] = (2230u << 16u);
    goto L_08B623D4;
L_08B623D4:
    ctx.gpr[22] = (32768u << 16u);
    goto L_08B623D8;
L_08B623D8:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(28)));
    goto L_08B623DC;
L_08B623DC:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[21] + static_cast<std::uint32_t>(12028)));
    goto L_08B623E0;
L_08B623E0:
    ctx.set_fpu_condition((ctx.fpr[12] < ctx.fpr[13]));
    goto L_08B623E4;
L_08B623E4:
    // nop
    goto L_08B623E8;
L_08B623E8:
    { const bool branch_taken = !ctx.fpu_condition();
    // nop
      if (branch_taken) {
          goto L_08B62438;
      }
      goto L_08B623F0;
    }
L_08B623EC:
    // nop
    goto L_08B623F0;
L_08B623F0:
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B623F4;
L_08B623F4:
    ctx.fpr[14] = ctx.fpr[12] / ctx.fpr[13];
    goto L_08B623F8;
L_08B623F8:
    ctx.set_fpu_condition((ctx.fpr[14] < ctx.fpr[24]));
    goto L_08B623FC;
L_08B623FC:
    // nop
    goto L_08B62400;
L_08B62400:
    { const bool branch_taken = !ctx.fpu_condition();
    // nop
      if (branch_taken) {
          goto L_08B62418;
      }
      goto L_08B62408;
    }
L_08B62404:
    // nop
    goto L_08B62408;
L_08B62408:
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[13];
    goto L_08B6240C;
L_08B6240C:
    ctx.fpr[12] = std::bit_cast<float>(ctx.fpu_float_to_word_ct<1u>(ctx.fpr[12]));
    goto L_08B62410;
L_08B62410:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
      if (branch_taken) {
          goto L_08B6242C;
      }
      goto L_08B62418;
    }
L_08B62414:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62418;
L_08B62418:
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[13];
    goto L_08B6241C;
L_08B6241C:
    ctx.fpr[12] = ctx.fpr[12] - ctx.fpr[24];
    goto L_08B62420;
L_08B62420:
    ctx.fpr[12] = std::bit_cast<float>(ctx.fpu_float_to_word_ct<1u>(ctx.fpr[12]));
    goto L_08B62424;
L_08B62424:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62428;
L_08B62428:
    ctx.gpr[4] = (ctx.gpr[4] + ctx.gpr[22]);
    goto L_08B6242C;
L_08B6242C:
    ctx.gpr[4] = (ctx.gpr[4] << 24u);
    goto L_08B62430;
L_08B62430:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[4] = (ctx.gpr[4] | ctx.gpr[23]);
      if (branch_taken) {
          goto L_08B6249C;
      }
      goto L_08B62438;
    }
L_08B62434:
    ctx.gpr[4] = (ctx.gpr[4] | ctx.gpr[23]);
    goto L_08B62438;
L_08B62438:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(24)));
    goto L_08B6243C;
L_08B6243C:
    ctx.fpr[12] = ctx.fpr[14] - ctx.fpr[12];
    goto L_08B62440;
L_08B62440:
    ctx.set_fpu_condition((ctx.fpr[12] < ctx.fpr[13]));
    goto L_08B62444;
L_08B62444:
    // nop
    goto L_08B62448;
L_08B62448:
    { const bool branch_taken = !ctx.fpu_condition();
    // nop
      if (branch_taken) {
          goto L_08B62498;
      }
      goto L_08B62450;
    }
L_08B6244C:
    // nop
    goto L_08B62450;
L_08B62450:
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B62454;
L_08B62454:
    ctx.fpr[14] = ctx.fpr[12] / ctx.fpr[13];
    goto L_08B62458;
L_08B62458:
    ctx.set_fpu_condition((ctx.fpr[14] < ctx.fpr[24]));
    goto L_08B6245C;
L_08B6245C:
    // nop
    goto L_08B62460;
L_08B62460:
    { const bool branch_taken = !ctx.fpu_condition();
    // nop
      if (branch_taken) {
          goto L_08B62478;
      }
      goto L_08B62468;
    }
L_08B62464:
    // nop
    goto L_08B62468;
L_08B62468:
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[13];
    goto L_08B6246C;
L_08B6246C:
    ctx.fpr[12] = std::bit_cast<float>(ctx.fpu_float_to_word_ct<1u>(ctx.fpr[12]));
    goto L_08B62470;
L_08B62470:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
      if (branch_taken) {
          goto L_08B6248C;
      }
      goto L_08B62478;
    }
L_08B62474:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62478;
L_08B62478:
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[13];
    goto L_08B6247C;
L_08B6247C:
    ctx.fpr[12] = ctx.fpr[12] - ctx.fpr[24];
    goto L_08B62480;
L_08B62480:
    ctx.fpr[12] = std::bit_cast<float>(ctx.fpu_float_to_word_ct<1u>(ctx.fpr[12]));
    goto L_08B62484;
L_08B62484:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62488;
L_08B62488:
    ctx.gpr[4] = (ctx.gpr[4] + ctx.gpr[22]);
    goto L_08B6248C;
L_08B6248C:
    ctx.gpr[4] = (ctx.gpr[4] << 24u);
    goto L_08B62490;
L_08B62490:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[4] = (ctx.gpr[4] | ctx.gpr[23]);
      if (branch_taken) {
          goto L_08B6249C;
      }
      goto L_08B62498;
    }
L_08B62494:
    ctx.gpr[4] = (ctx.gpr[4] | ctx.gpr[23]);
    goto L_08B62498;
L_08B62498:
    ctx.gpr[4] = (0u + static_cast<std::uint32_t>(-1));
    goto L_08B6249C;
L_08B6249C:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(0)));
    goto L_08B624A0;
L_08B624A0:
    ctx.gpr[7] = (ctx.gpr[4] | 0u);
    goto L_08B624A4;
L_08B624A4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B624A8;
L_08B624A8:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(4)));
    goto L_08B624AC;
L_08B624AC:
    ctx.gpr[4] = (ctx.gpr[19] | 0u);
    goto L_08B624B0;
L_08B624B0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B624B4;
L_08B624B4:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(8)));
    goto L_08B624B8;
L_08B624B8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), std::bit_cast<std::uint32_t>(ctx.fpr[26]));
    goto L_08B624BC;
L_08B624BC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B624C0;
L_08B624C0:
    ctx.gpr[5] = (ctx.gpr[30] | 0u);
    goto L_08B624C4;
L_08B624C4:
    ctx.gpr[31] = (0x08B624CCu);
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    ctx.pc = 0x0885CD60u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B624CCu) goto L_08B624CC;
    return;
L_08B624C8:
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    goto L_08B624CC;
L_08B624CC:
    ctx.gpr[20] = (ctx.gpr[20] + static_cast<std::uint32_t>(1));
    goto L_08B624D0;
L_08B624D0:
    ctx.gpr[19] = (ctx.gpr[19] + static_cast<std::uint32_t>(48));
    goto L_08B624D4;
L_08B624D4:
    ctx.gpr[4] = (static_cast<std::int32_t>(ctx.gpr[20]) < 80 ? 1u : 0u);
    goto L_08B624D8;
L_08B624D8:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.gpr[18] = (ctx.gpr[18] + static_cast<std::uint32_t>(32));
      if (branch_taken) {
          goto L_08B623D8;
      }
      goto L_08B624E0;
    }
L_08B624DC:
    ctx.gpr[18] = (ctx.gpr[18] + static_cast<std::uint32_t>(32));
    goto L_08B624E0;
L_08B624E0:
    ctx.gpr[31] = (0x08B624E8u);
    ctx.gpr[4] = (0u | 0u);
    ctx.pc = 0x0899FDC4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B624E8u) goto L_08B624E8;
    return;
L_08B624E4:
    ctx.gpr[4] = (0u | 0u);
    goto L_08B624E8;
L_08B624E8:
    ctx.gpr[31] = (0x08B624F0u);
    ctx.gpr[4] = (0u | 4u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B624F0u) goto L_08B624F0;
    return;
L_08B624EC:
    ctx.gpr[4] = (0u | 4u);
    goto L_08B624F0;
L_08B624F0:
    ctx.gpr[31] = (0x08B624F8u);
    ctx.gpr[4] = (0u | 9u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B624F8u) goto L_08B624F8;
    return;
L_08B624F4:
    ctx.gpr[4] = (0u | 9u);
    goto L_08B624F8;
L_08B624F8:
    ctx.gpr[31] = (0x08B62500u);
    ctx.gpr[4] = (0u | 1u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62500u) goto L_08B62500;
    return;
L_08B624FC:
    ctx.gpr[4] = (0u | 1u);
    goto L_08B62500;
L_08B62500:
    { const float fs = ctx.fpr[20]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B62504;
L_08B62504:
    ctx.fpr[12] = std::bit_cast<float>(ctx.fpu_float_to_word_ct<1u>(ctx.fpr[12]));
    goto L_08B62508;
L_08B62508:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B6250C;
L_08B6250C:
    ctx.gpr[4] = (ctx.gpr[4] & 255u);
    goto L_08B62510;
L_08B62510:
    ctx.gpr[4] = (ctx.gpr[4] << 24u);
    goto L_08B62514;
L_08B62514:
    ctx.gpr[31] = (0x08B6251Cu);
    ctx.gpr[4] = (ctx.gpr[4] | ctx.gpr[23]);
    ctx.pc = 0x089A0C20u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6251Cu) goto L_08B6251C;
    return;
L_08B62518:
    ctx.gpr[4] = (ctx.gpr[4] | ctx.gpr[23]);
    goto L_08B6251C;
L_08B6251C:
    ctx.gpr[31] = (0x08B62524u);
    ctx.gpr[4] = (0u | 1u);
    ctx.pc = 0x0899FFC8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62524u) goto L_08B62524;
    return;
L_08B62520:
    ctx.gpr[4] = (0u | 1u);
    goto L_08B62524;
L_08B62524:
    ctx.gpr[31] = (0x08B6252Cu);
    ctx.gpr[4] = (0u | 10u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6252Cu) goto L_08B6252C;
    return;
L_08B62528:
    ctx.gpr[4] = (0u | 10u);
    goto L_08B6252C;
L_08B6252C:
    ctx.gpr[31] = (0x08B62534u);
    ctx.gpr[4] = (0u | 11u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62534u) goto L_08B62534;
    return;
L_08B62530:
    ctx.gpr[4] = (0u | 11u);
    goto L_08B62534;
L_08B62534:
    ctx.gpr[31] = (0x08B6253Cu);
    ctx.gpr[4] = (0u | 12u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6253Cu) goto L_08B6253C;
    return;
L_08B62538:
    ctx.gpr[4] = (0u | 12u);
    goto L_08B6253C;
L_08B6253C:
    ctx.gpr[31] = (0x08B62544u);
    ctx.gpr[4] = (0u | 13u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62544u) goto L_08B62544;
    return;
L_08B62540:
    ctx.gpr[4] = (0u | 13u);
    goto L_08B62544;
L_08B62544:
    ctx.gpr[31] = (0x08B6254Cu);
    ctx.gpr[4] = (0u | 14u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6254Cu) goto L_08B6254C;
    return;
L_08B62548:
    ctx.gpr[4] = (0u | 14u);
    goto L_08B6254C;
L_08B6254C:
    ctx.gpr[4] = (0u | 0u);
    goto L_08B62550;
L_08B62550:
    ctx.gpr[5] = (0u | 2u);
    goto L_08B62554;
L_08B62554:
    ctx.gpr[6] = (0u | 3u);
    goto L_08B62558;
L_08B62558:
    ctx.gpr[7] = (0u | 0u);
    goto L_08B6255C;
L_08B6255C:
    ctx.gpr[31] = (0x08B62564u);
    ctx.gpr[8] = (0u | 0u);
    ctx.pc = 0x089A12A4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62564u) goto L_08B62564;
    return;
L_08B62560:
    ctx.gpr[8] = (0u | 0u);
    goto L_08B62564;
L_08B62564:
    ctx.gpr[31] = (0x08B6256Cu);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(16)));
    ctx.pc = 0x0899D2F8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6256Cu) goto L_08B6256C;
    return;
L_08B62568:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(16)));
    goto L_08B6256C;
L_08B6256C:
    ctx.gpr[31] = (0x08B62574u);
    ctx.gpr[4] = (0u | 2u);
    ctx.pc = 0x089A296Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62574u) goto L_08B62574;
    return;
L_08B62570:
    ctx.gpr[4] = (0u | 2u);
    goto L_08B62574;
L_08B62574:
    ctx.gpr[31] = (0x08B6257Cu);
    // nop
    ctx.pc = 0x089A250Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6257Cu) goto L_08B6257C;
    return;
L_08B62578:
    // nop
    goto L_08B6257C;
L_08B6257C:
    ctx.gpr[31] = (0x08B62584u);
    ctx.gpr[4] = (0u | 1u);
    ctx.pc = 0x089A119Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62584u) goto L_08B62584;
    return;
L_08B62580:
    ctx.gpr[4] = (0u | 1u);
    goto L_08B62584;
L_08B62584:
    ctx.gpr[4] = (0u | 6u);
    goto L_08B62588;
L_08B62588:
    ctx.gpr[5] = (0u | 415u);
    goto L_08B6258C;
L_08B6258C:
    ctx.gpr[6] = (0u | 160u);
    goto L_08B62590;
L_08B62590:
    ctx.gpr[7] = (0u | 0u);
    goto L_08B62594;
L_08B62594:
    ctx.gpr[31] = (0x08B6259Cu);
    ctx.gpr[8] = (ctx.gpr[17] | 0u);
    ctx.pc = 0x089A0520u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6259Cu) goto L_08B6259C;
    return;
L_08B62598:
    ctx.gpr[8] = (ctx.gpr[17] | 0u);
    goto L_08B6259C;
L_08B6259C:
    ctx.gpr[31] = (0x08B625A4u);
    ctx.gpr[4] = (0u | 0u);
    ctx.pc = 0x089A119Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B625A4u) goto L_08B625A4;
    return;
L_08B625A0:
    ctx.gpr[4] = (0u | 0u);
    goto L_08B625A4;
L_08B625A4:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(32)));
    goto L_08B625A8;
L_08B625A8:
    ctx.fpr[22] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(36)));
    goto L_08B625AC;
L_08B625AC:
    ctx.fpr[24] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(40)));
    goto L_08B625B0;
L_08B625B0:
    ctx.fpr[26] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(44)));
    goto L_08B625B4;
L_08B625B4:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(48)));
    goto L_08B625B8;
L_08B625B8:
    ctx.gpr[17] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(52)));
    goto L_08B625BC;
L_08B625BC:
    ctx.gpr[18] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(56)));
    goto L_08B625C0;
L_08B625C0:
    ctx.gpr[19] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(60)));
    goto L_08B625C4;
L_08B625C4:
    ctx.gpr[20] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(64)));
    goto L_08B625C8;
L_08B625C8:
    ctx.gpr[21] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(68)));
    goto L_08B625CC;
L_08B625CC:
    ctx.gpr[22] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(72)));
    goto L_08B625D0;
L_08B625D0:
    ctx.gpr[23] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(76)));
    goto L_08B625D4;
L_08B625D4:
    ctx.gpr[30] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(80)));
    goto L_08B625D8;
L_08B625D8:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(84)));
    goto L_08B625DC;
L_08B625DC:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(96));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B625E0:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(96));
    goto L_08B625E4;
L_08B625E4:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-272));
    goto L_08B625E8;
L_08B625E8:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(12)));
    goto L_08B625EC;
L_08B625EC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(240), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B625F0;
L_08B625F0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(244), ctx.gpr[16]);
    goto L_08B625F4;
L_08B625F4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(248), ctx.gpr[17]);
    goto L_08B625F8;
L_08B625F8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(252), ctx.gpr[18]);
    goto L_08B625FC;
L_08B625FC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(256), ctx.gpr[19]);
    goto L_08B62600;
L_08B62600:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(260), ctx.gpr[31]);
    goto L_08B62604;
L_08B62604:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
      if (branch_taken) {
          goto L_08B62614;
      }
      goto L_08B6260C;
    }
L_08B62608:
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
    goto L_08B6260C;
L_08B6260C:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62850;
      }
      goto L_08B62614;
    }
L_08B62610:
    // nop
    goto L_08B62614;
L_08B62614:
    ctx.gpr[4] = (2205u << 16u);
    goto L_08B62618;
L_08B62618:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(24256)));
    goto L_08B6261C;
L_08B6261C:
    ctx.gpr[17] = (ctx.gpr[4] + static_cast<std::uint32_t>(1824));
    goto L_08B62620;
L_08B62620:
    ctx.gpr[31] = (0x08B62628u);
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    ctx.pc = 0x0885EA90u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62628u) goto L_08B62628;
    return;
L_08B62624:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B62628;
L_08B62628:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(0)));
    goto L_08B6262C;
L_08B6262C:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(4)));
    goto L_08B62630;
L_08B62630:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(8)));
    goto L_08B62634;
L_08B62634:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62638;
L_08B62638:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(12)));
    goto L_08B6263C;
L_08B6263C:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B62640;
L_08B62640:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    goto L_08B62644;
L_08B62644:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B62648;
L_08B62648:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[5]);
    goto L_08B6264C;
L_08B6264C:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[15]));
    goto L_08B62650;
L_08B62650:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[6]);
    goto L_08B62654;
L_08B62654:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B62658;
L_08B62658:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[4]);
    goto L_08B6265C;
L_08B6265C:
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(184));
    goto L_08B62660;
L_08B62660:
    ctx.gpr[6] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[5] + static_cast<std::uint32_t>(0))))));
    goto L_08B62664;
L_08B62664:
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    goto L_08B62668;
L_08B62668:
    ctx.gpr[4] = (ctx.gpr[29] + static_cast<std::uint32_t>(224));
    goto L_08B6266C;
L_08B6266C:
    jump_target = ctx.gpr[7];
    ctx.gpr[31] = (0x08B62674u);
    ctx.gpr[5] = (ctx.gpr[16] + ctx.gpr[6]);
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62674u) goto L_08B62674;
    return;
L_08B62670:
    ctx.gpr[5] = (ctx.gpr[16] + ctx.gpr[6]);
    goto L_08B62674;
L_08B62674:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(228)));
    goto L_08B62678;
L_08B62678:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(224)));
    goto L_08B6267C;
L_08B6267C:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62680;
L_08B62680:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(232)));
    goto L_08B62684;
L_08B62684:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[4]);
    goto L_08B62688;
L_08B62688:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B6268C;
L_08B6268C:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(236)));
    goto L_08B62690;
L_08B62690:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B62694;
L_08B62694:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[5]);
    goto L_08B62698;
L_08B62698:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[4]);
    goto L_08B6269C;
L_08B6269C:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[15]));
    goto L_08B626A0;
L_08B626A0:
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(20)));
    goto L_08B626A4;
L_08B626A4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), ctx.gpr[4]);
    goto L_08B626A8;
L_08B626A8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    goto L_08B626AC;
L_08B626AC:
    ctx.gpr[18] = (ctx.gpr[29] + static_cast<std::uint32_t>(32));
    goto L_08B626B0;
L_08B626B0:
    ctx.gpr[31] = (0x08B626B8u);
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    ctx.pc = 0x0885EA90u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B626B8u) goto L_08B626B8;
    return;
L_08B626B4:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B626B8;
L_08B626B8:
    ctx.gpr[4] = (ctx.gpr[18] | 0u);
    goto L_08B626BC;
L_08B626BC:
    ctx.gpr[5] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B626C0;
L_08B626C0:
    ctx.gpr[31] = (0x08B626C8u);
    ctx.gpr[6] = (ctx.gpr[2] | 0u);
    ctx.pc = 0x089A38FCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B626C8u) goto L_08B626C8;
    return;
L_08B626C4:
    ctx.gpr[6] = (ctx.gpr[2] | 0u);
    goto L_08B626C8;
L_08B626C8:
    ctx.fpr[20] = std::bit_cast<float>(0u);
    goto L_08B626CC;
L_08B626CC:
    ctx.gpr[4] = (ctx.gpr[18] | 0u);
    goto L_08B626D0;
L_08B626D0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(36), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B626D4;
L_08B626D4:
    ctx.gpr[31] = (0x08B626DCu);
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    ctx.pc = 0x089A3BC8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B626DCu) goto L_08B626DC;
    return;
L_08B626D8:
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    goto L_08B626DC;
L_08B626DC:
    ctx.gpr[17] = (ctx.gpr[29] + static_cast<std::uint32_t>(48));
    goto L_08B626E0;
L_08B626E0:
    ctx.gpr[31] = (0x08B626E8u);
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    ctx.pc = 0x089A3EBCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B626E8u) goto L_08B626E8;
    return;
L_08B626E4:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B626E8;
L_08B626E8:
    ctx.gpr[19] = (ctx.gpr[29] + static_cast<std::uint32_t>(80));
    goto L_08B626EC;
L_08B626EC:
    ctx.gpr[6] = (49024u << 16u);
    goto L_08B626F0;
L_08B626F0:
    ctx.gpr[4] = (ctx.gpr[19] | 0u);
    goto L_08B626F4;
L_08B626F4:
    ctx.fpr[12] = std::bit_cast<float>(ctx.gpr[6]);
    goto L_08B626F8;
L_08B626F8:
    ctx.gpr[31] = (0x08B62700u);
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    ctx.pc = 0x089A3A64u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62700u) goto L_08B62700;
    return;
L_08B626FC:
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    goto L_08B62700;
L_08B62700:
    ctx.gpr[5] = (ctx.gpr[29] + static_cast<std::uint32_t>(64));
    goto L_08B62704;
L_08B62704:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B62708;
L_08B62708:
    ctx.gpr[31] = (0x08B62710u);
    ctx.gpr[6] = (ctx.gpr[19] | 0u);
    ctx.pc = 0x089A3B30u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62710u) goto L_08B62710;
    return;
L_08B6270C:
    ctx.gpr[6] = (ctx.gpr[19] | 0u);
    goto L_08B62710;
L_08B62710:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(92), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B62714;
L_08B62714:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(76), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B62718;
L_08B62718:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(60), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B6271C;
L_08B6271C:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B62720;
L_08B62720:
    ctx.gpr[5] = (ctx.gpr[17] | 0u);
    goto L_08B62724;
L_08B62724:
    ctx.gpr[31] = (0x08B6272Cu);
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    ctx.pc = 0x089A4094u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6272Cu) goto L_08B6272C;
    return;
L_08B62728:
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    goto L_08B6272C;
L_08B6272C:
    ctx.gpr[18] = (ctx.gpr[29] + static_cast<std::uint32_t>(112));
    goto L_08B62730;
L_08B62730:
    ctx.gpr[31] = (0x08B62738u);
    ctx.gpr[4] = (ctx.gpr[18] | 0u);
    ctx.pc = 0x0886EE24u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62738u) goto L_08B62738;
    return;
L_08B62734:
    ctx.gpr[4] = (ctx.gpr[18] | 0u);
    goto L_08B62738;
L_08B62738:
    ctx.gpr[4] = (ctx.gpr[18] | 0u);
    goto L_08B6273C;
L_08B6273C:
    ctx.gpr[31] = (0x08B62744u);
    ctx.gpr[5] = (ctx.gpr[17] | 0u);
    ctx.pc = 0x089A3EFCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62744u) goto L_08B62744;
    return;
L_08B62740:
    ctx.gpr[5] = (ctx.gpr[17] | 0u);
    goto L_08B62744;
L_08B62744:
    ctx.gpr[4] = (16256u << 16u);
    goto L_08B62748;
L_08B62748:
    ctx.fpr[12] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B6274C;
L_08B6274C:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B62750;
L_08B62750:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(176), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62754;
L_08B62754:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(168));
    goto L_08B62758;
L_08B62758:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[4] + static_cast<std::uint32_t>(0))))));
    goto L_08B6275C;
L_08B6275C:
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B62760;
L_08B62760:
    jump_target = ctx.gpr[6];
    ctx.gpr[31] = (0x08B62768u);
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62768u) goto L_08B62768;
    return;
L_08B62764:
    ctx.gpr[4] = (ctx.gpr[16] + ctx.gpr[5]);
    goto L_08B62768;
L_08B62768:
    ctx.gpr[4] = (17279u << 16u);
    goto L_08B6276C;
L_08B6276C:
    ctx.fpr[12] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B62770;
L_08B62770:
    ctx.gpr[6] = (0u + static_cast<std::uint32_t>(-2));
    goto L_08B62774;
L_08B62774:
    { const float fs = ctx.fpr[0]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B62778;
L_08B62778:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(184)));
    goto L_08B6277C;
L_08B6277C:
    ctx.gpr[5] = (256u << 16u);
    goto L_08B62780;
L_08B62780:
    ctx.gpr[4] = (ctx.gpr[4] & ctx.gpr[6]);
    goto L_08B62784;
L_08B62784:
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(-1));
    goto L_08B62788;
L_08B62788:
    ctx.fpr[12] = std::bit_cast<float>(ctx.fpu_float_to_word_ct<1u>(ctx.fpr[12]));
    goto L_08B6278C;
L_08B6278C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(184), ctx.gpr[4]);
    goto L_08B62790;
L_08B62790:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62794;
L_08B62794:
    ctx.gpr[6] = (ctx.gpr[6] & 255u);
    goto L_08B62798;
L_08B62798:
    ctx.gpr[6] = (ctx.gpr[6] << 24u);
    goto L_08B6279C;
L_08B6279C:
    ctx.gpr[5] = (ctx.gpr[6] | ctx.gpr[5]);
    goto L_08B627A0;
L_08B627A0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(180), ctx.gpr[5]);
    goto L_08B627A4;
L_08B627A4:
    ctx.gpr[5] = (0u + static_cast<std::uint32_t>(-3));
    goto L_08B627A8;
L_08B627A8:
    ctx.gpr[4] = (ctx.gpr[4] & ctx.gpr[5]);
    goto L_08B627AC;
L_08B627AC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(184), ctx.gpr[4]);
    goto L_08B627B0;
L_08B627B0:
    ctx.gpr[5] = (0u + static_cast<std::uint32_t>(-5));
    goto L_08B627B4;
L_08B627B4:
    ctx.gpr[4] = (ctx.gpr[4] & ctx.gpr[5]);
    goto L_08B627B8;
L_08B627B8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(184), ctx.gpr[4]);
    goto L_08B627BC;
L_08B627BC:
    ctx.gpr[31] = (0x08B627C4u);
    ctx.gpr[4] = (0u | 0u);
    ctx.pc = 0x0899FDC4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B627C4u) goto L_08B627C4;
    return;
L_08B627C0:
    ctx.gpr[4] = (0u | 0u);
    goto L_08B627C4;
L_08B627C4:
    ctx.gpr[31] = (0x08B627CCu);
    ctx.gpr[4] = (0u | 4u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B627CCu) goto L_08B627CC;
    return;
L_08B627C8:
    ctx.gpr[4] = (0u | 4u);
    goto L_08B627CC;
L_08B627CC:
    ctx.gpr[31] = (0x08B627D4u);
    ctx.gpr[4] = (0u | 9u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B627D4u) goto L_08B627D4;
    return;
L_08B627D0:
    ctx.gpr[4] = (0u | 9u);
    goto L_08B627D4;
L_08B627D4:
    ctx.gpr[31] = (0x08B627DCu);
    ctx.gpr[4] = (0u | 1u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B627DCu) goto L_08B627DC;
    return;
L_08B627D8:
    ctx.gpr[4] = (0u | 1u);
    goto L_08B627DC;
L_08B627DC:
    ctx.gpr[31] = (0x08B627E4u);
    ctx.gpr[4] = (0u | 1u);
    ctx.pc = 0x0899FFC8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B627E4u) goto L_08B627E4;
    return;
L_08B627E0:
    ctx.gpr[4] = (0u | 1u);
    goto L_08B627E4;
L_08B627E4:
    ctx.gpr[31] = (0x08B627ECu);
    ctx.gpr[4] = (0u | 10u);
    ctx.pc = 0x089A0384u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B627ECu) goto L_08B627EC;
    return;
L_08B627E8:
    ctx.gpr[4] = (0u | 10u);
    goto L_08B627EC;
L_08B627EC:
    ctx.gpr[31] = (0x08B627F4u);
    ctx.gpr[4] = (0u | 11u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B627F4u) goto L_08B627F4;
    return;
L_08B627F0:
    ctx.gpr[4] = (0u | 11u);
    goto L_08B627F4;
L_08B627F4:
    ctx.gpr[31] = (0x08B627FCu);
    ctx.gpr[4] = (0u | 12u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B627FCu) goto L_08B627FC;
    return;
L_08B627F8:
    ctx.gpr[4] = (0u | 12u);
    goto L_08B627FC;
L_08B627FC:
    ctx.gpr[31] = (0x08B62804u);
    ctx.gpr[4] = (0u | 13u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62804u) goto L_08B62804;
    return;
L_08B62800:
    ctx.gpr[4] = (0u | 13u);
    goto L_08B62804;
L_08B62804:
    ctx.gpr[31] = (0x08B6280Cu);
    ctx.gpr[4] = (0u | 14u);
    ctx.pc = 0x089A03DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6280Cu) goto L_08B6280C;
    return;
L_08B62808:
    ctx.gpr[4] = (0u | 14u);
    goto L_08B6280C;
L_08B6280C:
    ctx.gpr[17] = (ctx.gpr[29] + static_cast<std::uint32_t>(192));
    goto L_08B62810;
L_08B62810:
    ctx.gpr[31] = (0x08B62818u);
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    ctx.pc = 0x0886F028u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62818u) goto L_08B62818;
    return;
L_08B62814:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B62818;
L_08B62818:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B6281C;
L_08B6281C:
    ctx.gpr[5] = (0u | 0u);
    goto L_08B62820;
L_08B62820:
    ctx.gpr[31] = (0x08B62828u);
    ctx.gpr[6] = (0u | 20u);
    ctx.pc = 0x08935828u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62828u) goto L_08B62828;
    return;
L_08B62824:
    ctx.gpr[6] = (0u | 20u);
    goto L_08B62828;
L_08B62828:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(12)));
    goto L_08B6282C;
L_08B6282C:
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    goto L_08B62830;
L_08B62830:
    ctx.gpr[31] = (0x08B62838u);
    ctx.gpr[6] = (ctx.gpr[17] | 0u);
    ctx.pc = 0x0886ACCCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62838u) goto L_08B62838;
    return;
L_08B62834:
    ctx.gpr[6] = (ctx.gpr[17] | 0u);
    goto L_08B62838;
L_08B62838:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B6283C;
L_08B6283C:
    ctx.gpr[31] = (0x08B62844u);
    ctx.gpr[5] = (0u | 2u);
    ctx.pc = 0x0886F048u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62844u) goto L_08B62844;
    return;
L_08B62840:
    ctx.gpr[5] = (0u | 2u);
    goto L_08B62844;
L_08B62844:
    ctx.gpr[4] = (ctx.gpr[18] | 0u);
    goto L_08B62848;
L_08B62848:
    ctx.gpr[31] = (0x08B62850u);
    ctx.gpr[5] = (0u | 2u);
    ctx.pc = 0x0886EE90u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62850u) goto L_08B62850;
    return;
L_08B6284C:
    ctx.gpr[5] = (0u | 2u);
    goto L_08B62850;
L_08B62850:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(240)));
    goto L_08B62854;
L_08B62854:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(244)));
    goto L_08B62858;
L_08B62858:
    ctx.gpr[17] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(248)));
    goto L_08B6285C;
L_08B6285C:
    ctx.gpr[18] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(252)));
    goto L_08B62860;
L_08B62860:
    ctx.gpr[19] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(256)));
    goto L_08B62864;
L_08B62864:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(260)));
    goto L_08B62868;
L_08B62868:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(272));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B6286C:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(272));
    goto L_08B62870;
L_08B62870:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-144));
    goto L_08B62874;
L_08B62874:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(100), ctx.gpr[16]);
    goto L_08B62878;
L_08B62878:
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
    goto L_08B6287C;
L_08B6287C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(88), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B62880;
L_08B62880:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(92), std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B62884;
L_08B62884:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(96), std::bit_cast<std::uint32_t>(ctx.fpr[24]));
    goto L_08B62888;
L_08B62888:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(104), ctx.gpr[17]);
    goto L_08B6288C;
L_08B6288C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(108), ctx.gpr[18]);
    goto L_08B62890;
L_08B62890:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(112), ctx.gpr[19]);
    goto L_08B62894;
L_08B62894:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(116), ctx.gpr[20]);
    goto L_08B62898;
L_08B62898:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(120), ctx.gpr[21]);
    goto L_08B6289C;
L_08B6289C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(124), ctx.gpr[22]);
    goto L_08B628A0;
L_08B628A0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(128), ctx.gpr[31]);
    goto L_08B628A4;
L_08B628A4:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B628A8;
L_08B628A8:
    ctx.gpr[7] = (2230u << 16u);
    goto L_08B628AC;
L_08B628AC:
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(184));
    goto L_08B628B0;
L_08B628B0:
    ctx.gpr[6] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[5] + static_cast<std::uint32_t>(0))))));
    goto L_08B628B4;
L_08B628B4:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(11956)));
    goto L_08B628B8;
L_08B628B8:
    ctx.gpr[7] = (2230u << 16u);
    goto L_08B628BC;
L_08B628BC:
    ctx.fpr[22] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(11960)));
    goto L_08B628C0;
L_08B628C0:
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    goto L_08B628C4;
L_08B628C4:
    ctx.gpr[4] = (ctx.gpr[29] + static_cast<std::uint32_t>(48));
    goto L_08B628C8;
L_08B628C8:
    jump_target = ctx.gpr[7];
    ctx.gpr[31] = (0x08B628D0u);
    ctx.gpr[5] = (ctx.gpr[16] + ctx.gpr[6]);
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B628D0u) goto L_08B628D0;
    return;
L_08B628CC:
    ctx.gpr[5] = (ctx.gpr[16] + ctx.gpr[6]);
    goto L_08B628D0;
L_08B628D0:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(48)));
    goto L_08B628D4;
L_08B628D4:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(52)));
    goto L_08B628D8;
L_08B628D8:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B628DC;
L_08B628DC:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(56)));
    goto L_08B628E0;
L_08B628E0:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B628E4;
L_08B628E4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    goto L_08B628E8;
L_08B628E8:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B628EC;
L_08B628EC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[5]);
    goto L_08B628F0;
L_08B628F0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[4]);
    goto L_08B628F4;
L_08B628F4:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B628F8;
L_08B628F8:
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B628FC;
L_08B628FC:
    ctx.fpr[17] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(60)));
    goto L_08B62900;
L_08B62900:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[15]));
    goto L_08B62904;
L_08B62904:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08B62908;
L_08B62908:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    goto L_08B6290C;
L_08B6290C:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[17]));
    goto L_08B62910;
L_08B62910:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), ctx.gpr[4]);
    goto L_08B62914;
L_08B62914:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[6]);
    goto L_08B62918;
L_08B62918:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B6291C;
L_08B6291C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(32), ctx.gpr[5]);
    goto L_08B62920;
L_08B62920:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(36), ctx.gpr[4]);
    goto L_08B62924;
L_08B62924:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(28)));
    goto L_08B62928;
L_08B62928:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(32)));
    goto L_08B6292C;
L_08B6292C:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B62930;
L_08B62930:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(36)));
    goto L_08B62934;
L_08B62934:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B62938;
L_08B62938:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[4]);
    goto L_08B6293C;
L_08B6293C:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[15]));
    goto L_08B62940;
L_08B62940:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[5]);
    goto L_08B62944;
L_08B62944:
    ctx.gpr[31] = (0x08B6294Cu);
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[4]);
    ctx.pc = 0x08899300u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6294Cu) goto L_08B6294C;
    return;
L_08B62948:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[4]);
    goto L_08B6294C;
L_08B6294C:
    ctx.gpr[16] = (ctx.gpr[2] | 0u);
    goto L_08B62950;
L_08B62950:
    ctx.gpr[31] = (0x08B62958u);
    ctx.gpr[4] = (ctx.gpr[16] | 0u);
    ctx.pc = 0x08897EFCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62958u) goto L_08B62958;
    return;
L_08B62954:
    ctx.gpr[4] = (ctx.gpr[16] | 0u);
    goto L_08B62958;
L_08B62958:
    ctx.gpr[4] = (2230u << 16u);
    goto L_08B6295C;
L_08B6295C:
    ctx.gpr[17] = (ctx.gpr[2] | 0u);
    goto L_08B62960;
L_08B62960:
    ctx.fpr[24] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(11952)));
    goto L_08B62964;
L_08B62964:
    ctx.gpr[18] = (0u | 0u);
    goto L_08B62968;
L_08B62968:
    ctx.gpr[4] = (static_cast<std::int32_t>(ctx.gpr[18]) < static_cast<std::int32_t>(ctx.gpr[17]) ? 1u : 0u);
    goto L_08B6296C;
L_08B6296C:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.gpr[20] = (2230u << 16u);
      if (branch_taken) {
          goto L_08B62A68;
      }
      goto L_08B62974;
    }
L_08B62970:
    ctx.gpr[20] = (2230u << 16u);
    goto L_08B62974;
L_08B62974:
    ctx.gpr[21] = (ctx.gpr[29] + static_cast<std::uint32_t>(64));
    goto L_08B62978;
L_08B62978:
    ctx.gpr[22] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B6297C;
L_08B6297C:
    ctx.gpr[20] = (ctx.gpr[20] + static_cast<std::uint32_t>(12032));
    goto L_08B62980;
L_08B62980:
    ctx.gpr[4] = (ctx.gpr[16] | 0u);
    goto L_08B62984;
L_08B62984:
    ctx.gpr[31] = (0x08B6298Cu);
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    ctx.pc = 0x08897EA4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B6298Cu) goto L_08B6298C;
    return;
L_08B62988:
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    goto L_08B6298C;
L_08B6298C:
    ctx.gpr[19] = (ctx.gpr[2] | 0u);
    goto L_08B62990;
L_08B62990:
    { const bool branch_taken = ctx.gpr[19] != 0u;
    // nop
      if (branch_taken) {
          goto L_08B629A0;
      }
      goto L_08B62998;
    }
L_08B62994:
    // nop
    goto L_08B62998;
L_08B62998:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62A58;
      }
      goto L_08B629A0;
    }
L_08B6299C:
    // nop
    goto L_08B629A0;
L_08B629A0:
    ctx.gpr[31] = (0x08B629A8u);
    ctx.gpr[4] = (ctx.gpr[19] | 0u);
    ctx.pc = 0x089359E8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B629A8u) goto L_08B629A8;
    return;
L_08B629A4:
    ctx.gpr[4] = (ctx.gpr[19] | 0u);
    goto L_08B629A8;
L_08B629A8:
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
    goto L_08B629AC;
L_08B629AC:
    ctx.gpr[5] = (static_cast<std::int32_t>(ctx.gpr[4]) < 6 ? 1u : 0u);
    goto L_08B629B0;
L_08B629B0:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B629C0;
      }
      goto L_08B629B8;
    }
L_08B629B4:
    // nop
    goto L_08B629B8;
L_08B629B8:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62A58;
      }
      goto L_08B629C0;
    }
L_08B629BC:
    // nop
    goto L_08B629C0;
L_08B629C0:
    ctx.gpr[4] = (ctx.gpr[19] + ctx.gpr[4]);
    goto L_08B629C4;
L_08B629C4:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(-6));
    goto L_08B629C8;
L_08B629C8:
    ctx.gpr[5] = (ctx.gpr[20] | 0u);
    goto L_08B629CC;
L_08B629CC:
    ctx.gpr[31] = (0x08B629D4u);
    ctx.gpr[6] = (0u | 3u);
    ctx.pc = 0x08935B50u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B629D4u) goto L_08B629D4;
    return;
L_08B629D0:
    ctx.gpr[6] = (0u | 3u);
    goto L_08B629D4;
L_08B629D4:
    { const bool branch_taken = ctx.gpr[2] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B629E4;
      }
      goto L_08B629DC;
    }
L_08B629D8:
    // nop
    goto L_08B629DC;
L_08B629DC:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62A58;
      }
      goto L_08B629E4;
    }
L_08B629E0:
    // nop
    goto L_08B629E4;
L_08B629E4:
    ctx.gpr[4] = (ctx.gpr[16] | 0u);
    goto L_08B629E8;
L_08B629E8:
    ctx.gpr[31] = (0x08B629F0u);
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    ctx.pc = 0x08897998u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B629F0u) goto L_08B629F0;
    return;
L_08B629EC:
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    goto L_08B629F0;
L_08B629F0:
    { const bool branch_taken = ctx.gpr[2] != 0u;
    // nop
      if (branch_taken) {
          goto L_08B62A00;
      }
      goto L_08B629F8;
    }
L_08B629F4:
    // nop
    goto L_08B629F8;
L_08B629F8:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62A58;
      }
      goto L_08B62A00;
    }
L_08B629FC:
    // nop
    goto L_08B62A00;
L_08B62A00:
    ctx.gpr[4] = (ctx.gpr[16] | 0u);
    goto L_08B62A04;
L_08B62A04:
    ctx.gpr[31] = (0x08B62A0Cu);
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    ctx.pc = 0x08897DECu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62A0Cu) goto L_08B62A0C;
    return;
L_08B62A08:
    ctx.gpr[5] = (ctx.gpr[18] | 0u);
    goto L_08B62A0C;
L_08B62A0C:
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
    goto L_08B62A10;
L_08B62A10:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    // nop
      if (branch_taken) {
          goto L_08B62A20;
      }
      goto L_08B62A18;
    }
L_08B62A14:
    // nop
    goto L_08B62A18;
L_08B62A18:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62A58;
      }
      goto L_08B62A20;
    }
L_08B62A1C:
    // nop
    goto L_08B62A20;
L_08B62A20:
    ctx.gpr[5] = (ctx.gpr[4] | 0u);
    goto L_08B62A24;
L_08B62A24:
    ctx.gpr[4] = (ctx.gpr[21] | 0u);
    goto L_08B62A28;
L_08B62A28:
    ctx.gpr[31] = (0x08B62A30u);
    ctx.gpr[6] = (ctx.gpr[22] | 0u);
    ctx.pc = 0x089A3528u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62A30u) goto L_08B62A30;
    return;
L_08B62A2C:
    ctx.gpr[6] = (ctx.gpr[22] | 0u);
    goto L_08B62A30;
L_08B62A30:
    ctx.gpr[31] = (0x08B62A38u);
    ctx.gpr[4] = (ctx.gpr[21] | 0u);
    ctx.pc = 0x089A37DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62A38u) goto L_08B62A38;
    return;
L_08B62A34:
    ctx.gpr[4] = (ctx.gpr[21] | 0u);
    goto L_08B62A38;
L_08B62A38:
    ctx.fpr[12] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[0]));
    goto L_08B62A3C;
L_08B62A3C:
    ctx.set_fpu_condition((ctx.fpr[12] < ctx.fpr[24]));
    goto L_08B62A40;
L_08B62A40:
    // nop
    goto L_08B62A44;
L_08B62A44:
    { const bool branch_taken = ctx.fpu_condition();
    // nop
      if (branch_taken) {
          goto L_08B62A54;
      }
      goto L_08B62A4C;
    }
L_08B62A48:
    // nop
    goto L_08B62A4C;
L_08B62A4C:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62A58;
      }
      goto L_08B62A54;
    }
L_08B62A50:
    // nop
    goto L_08B62A54;
L_08B62A54:
    ctx.fpr[24] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62A58;
L_08B62A58:
    ctx.gpr[18] = (ctx.gpr[18] + static_cast<std::uint32_t>(1));
    goto L_08B62A5C;
L_08B62A5C:
    ctx.gpr[4] = (static_cast<std::int32_t>(ctx.gpr[18]) < static_cast<std::int32_t>(ctx.gpr[17]) ? 1u : 0u);
    goto L_08B62A60;
L_08B62A60:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    // nop
      if (branch_taken) {
          goto L_08B62980;
      }
      goto L_08B62A68;
    }
L_08B62A64:
    // nop
    goto L_08B62A68;
L_08B62A68:
    ctx.set_fpu_condition((ctx.fpr[20] < ctx.fpr[24]));
    goto L_08B62A6C;
L_08B62A6C:
    // nop
    goto L_08B62A70;
L_08B62A70:
    { const bool branch_taken = !ctx.fpu_condition();
    // nop
      if (branch_taken) {
          goto L_08B62AA4;
      }
      goto L_08B62A78;
    }
L_08B62A74:
    // nop
    goto L_08B62A78;
L_08B62A78:
    ctx.set_fpu_condition((ctx.fpr[22] < ctx.fpr[24]));
    goto L_08B62A7C;
L_08B62A7C:
    // nop
    goto L_08B62A80;
L_08B62A80:
    { const bool branch_taken = ctx.fpu_condition();
    // nop
      if (branch_taken) {
          goto L_08B62AB0;
      }
      goto L_08B62A88;
    }
L_08B62A84:
    // nop
    goto L_08B62A88;
L_08B62A88:
    ctx.fpr[12] = ctx.fpr[24] - ctx.fpr[20];
    goto L_08B62A8C;
L_08B62A8C:
    ctx.fpr[13] = ctx.fpr[22] - ctx.fpr[20];
    goto L_08B62A90;
L_08B62A90:
    ctx.fpr[0] = ctx.fpr[12] / ctx.fpr[13];
    goto L_08B62A94;
L_08B62A94:
    ctx.gpr[4] = (16256u << 16u);
    goto L_08B62A98;
L_08B62A98:
    ctx.fpr[14] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B62A9C;
L_08B62A9C:
    { const bool branch_taken = 0u == 0u;
    ctx.fpr[0] = ctx.fpr[14] - ctx.fpr[0];
      if (branch_taken) {
          goto L_08B62AB4;
      }
      goto L_08B62AA4;
    }
L_08B62AA0:
    ctx.fpr[0] = ctx.fpr[14] - ctx.fpr[0];
    goto L_08B62AA4;
L_08B62AA4:
    ctx.gpr[4] = (16256u << 16u);
    goto L_08B62AA8;
L_08B62AA8:
    { const bool branch_taken = 0u == 0u;
    ctx.fpr[0] = std::bit_cast<float>(ctx.gpr[4]);
      if (branch_taken) {
          goto L_08B62AB4;
      }
      goto L_08B62AB0;
    }
L_08B62AAC:
    ctx.fpr[0] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B62AB0;
L_08B62AB0:
    ctx.fpr[0] = std::bit_cast<float>(0u);
    goto L_08B62AB4;
L_08B62AB4:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(88)));
    goto L_08B62AB8;
L_08B62AB8:
    ctx.fpr[22] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(92)));
    goto L_08B62ABC;
L_08B62ABC:
    ctx.fpr[24] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(96)));
    goto L_08B62AC0;
L_08B62AC0:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(100)));
    goto L_08B62AC4;
L_08B62AC4:
    ctx.gpr[17] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(104)));
    goto L_08B62AC8;
L_08B62AC8:
    ctx.gpr[18] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(108)));
    goto L_08B62ACC;
L_08B62ACC:
    ctx.gpr[19] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(112)));
    goto L_08B62AD0;
L_08B62AD0:
    ctx.gpr[20] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(116)));
    goto L_08B62AD4;
L_08B62AD4:
    ctx.gpr[21] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(120)));
    goto L_08B62AD8;
L_08B62AD8:
    ctx.gpr[22] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(124)));
    goto L_08B62ADC;
L_08B62ADC:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(128)));
    goto L_08B62AE0;
L_08B62AE0:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(144));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B62AE4:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(144));
    goto L_08B62AE8;
L_08B62AE8:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-80));
    goto L_08B62AEC;
L_08B62AEC:
    ctx.gpr[4] = (16256u << 16u);
    goto L_08B62AF0;
L_08B62AF0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B62AF4;
L_08B62AF4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(32), std::bit_cast<std::uint32_t>(ctx.fpr[28]));
    goto L_08B62AF8;
L_08B62AF8:
    ctx.fpr[22] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B62AFC;
L_08B62AFC:
    ctx.fpr[28] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B62B00;
L_08B62B00:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), std::bit_cast<std::uint32_t>(ctx.fpr[24]));
    goto L_08B62B04;
L_08B62B04:
    ctx.fpr[24] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08B62B08;
L_08B62B08:
    ctx.gpr[4] = (16640u << 16u);
    goto L_08B62B0C;
L_08B62B0C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B62B10;
L_08B62B10:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), std::bit_cast<std::uint32_t>(ctx.fpr[26]));
    goto L_08B62B14;
L_08B62B14:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(36), std::bit_cast<std::uint32_t>(ctx.fpr[30]));
    goto L_08B62B18;
L_08B62B18:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(40), ctx.gpr[16]);
    goto L_08B62B1C;
L_08B62B1C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(44), ctx.gpr[17]);
    goto L_08B62B20;
L_08B62B20:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(48), ctx.gpr[18]);
    goto L_08B62B24;
L_08B62B24:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(52), ctx.gpr[19]);
    goto L_08B62B28;
L_08B62B28:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(56), ctx.gpr[20]);
    goto L_08B62B2C;
L_08B62B2C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(60), ctx.gpr[21]);
    goto L_08B62B30;
L_08B62B30:
    ctx.fpr[20] = std::bit_cast<float>(0u);
    goto L_08B62B34;
L_08B62B34:
    ctx.gpr[16] = (0u | 0u);
    goto L_08B62B38;
L_08B62B38:
    ctx.fpr[30] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B62B3C;
L_08B62B3C:
    ctx.gpr[17] = (0u | 1u);
    goto L_08B62B40;
L_08B62B40:
    ctx.gpr[18] = (0u | 2u);
    goto L_08B62B44;
L_08B62B44:
    ctx.gpr[19] = (0u | 3u);
    goto L_08B62B48;
L_08B62B48:
    ctx.gpr[20] = (0u | 21u);
    goto L_08B62B4C;
L_08B62B4C:
    ctx.fpr[26] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(12)));
    goto L_08B62B50;
L_08B62B50:
    ctx.gpr[21] = (2205u << 16u);
    goto L_08B62B54;
L_08B62B54:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(64), ctx.gpr[31]);
    goto L_08B62B58;
L_08B62B58:
    ctx.gpr[31] = (0x08B62B60u);
    ctx.gpr[4] = (ctx.gpr[16] | 0u);
    ctx.pc = 0x08841F84u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62B60u) goto L_08B62B60;
    return;
L_08B62B5C:
    ctx.gpr[4] = (ctx.gpr[16] | 0u);
    goto L_08B62B60;
L_08B62B60:
    ctx.gpr[16] = (ctx.gpr[2] | 0u);
    goto L_08B62B64;
L_08B62B64:
    { const bool branch_taken = ctx.gpr[16] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62CB0;
      }
      goto L_08B62B6C;
    }
L_08B62B68:
    // nop
    goto L_08B62B6C;
L_08B62B6C:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(1444)));
    goto L_08B62B70;
L_08B62B70:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62B98;
      }
      goto L_08B62B78;
    }
L_08B62B74:
    // nop
    goto L_08B62B78;
L_08B62B78:
    ctx.gpr[4] = (aot_mem.aot_load8(ctx.gpr[4] + static_cast<std::uint32_t>(105)));
    goto L_08B62B7C;
L_08B62B7C:
    ctx.gpr[4] = (ctx.gpr[4] & 8u);
    goto L_08B62B80;
L_08B62B80:
    ctx.gpr[4] = (0u < ctx.gpr[4] ? 1u : 0u);
    goto L_08B62B84;
L_08B62B84:
    ctx.gpr[4] = (ctx.gpr[4] & 255u);
    goto L_08B62B88;
L_08B62B88:
    { const bool branch_taken = ctx.gpr[4] != ctx.gpr[17];
    // nop
      if (branch_taken) {
          goto L_08B62B98;
      }
      goto L_08B62B90;
    }
L_08B62B8C:
    // nop
    goto L_08B62B90;
L_08B62B90:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62CA8;
      }
      goto L_08B62B98;
    }
L_08B62B94:
    // nop
    goto L_08B62B98;
L_08B62B98:
    ctx.gpr[31] = (0x08B62BA0u);
    ctx.gpr[4] = (ctx.gpr[16] | 0u);
    ctx.pc = 0x08838300u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62BA0u) goto L_08B62BA0;
    return;
L_08B62B9C:
    ctx.gpr[4] = (ctx.gpr[16] | 0u);
    goto L_08B62BA0;
L_08B62BA0:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(4368)));
    goto L_08B62BA4;
L_08B62BA4:
    ctx.fpr[12] = ctx.fpr[12] - ctx.fpr[0];
    goto L_08B62BA8;
L_08B62BA8:
    ctx.set_fpu_condition((ctx.fpr[12] < ctx.fpr[20]));
    goto L_08B62BAC;
L_08B62BAC:
    // nop
    goto L_08B62BB0;
L_08B62BB0:
    { const bool branch_taken = !ctx.fpu_condition();
    // nop
      if (branch_taken) {
          goto L_08B62BBC;
      }
      goto L_08B62BB8;
    }
L_08B62BB4:
    // nop
    goto L_08B62BB8;
L_08B62BB8:
    ctx.fpr[12] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B62BBC;
L_08B62BBC:
    ctx.set_fpu_condition((ctx.fpr[12] <= ctx.fpr[20]));
    goto L_08B62BC0;
L_08B62BC0:
    // nop
    goto L_08B62BC4;
L_08B62BC4:
    { const bool branch_taken = ctx.fpu_condition();
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4368), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
      if (branch_taken) {
          goto L_08B62BD4;
      }
      goto L_08B62BCC;
    }
L_08B62BC8:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4368), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62BCC;
L_08B62BCC:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62CA8;
      }
      goto L_08B62BD4;
    }
L_08B62BD0:
    // nop
    goto L_08B62BD4;
L_08B62BD4:
    ctx.gpr[4] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[16] + static_cast<std::uint32_t>(384))))));
    goto L_08B62BD8;
L_08B62BD8:
    { const bool branch_taken = ctx.gpr[4] == ctx.gpr[18];
    // nop
      if (branch_taken) {
          goto L_08B62BF0;
      }
      goto L_08B62BE0;
    }
L_08B62BDC:
    // nop
    goto L_08B62BE0;
L_08B62BE0:
    { const bool branch_taken = ctx.gpr[4] == ctx.gpr[19];
    // nop
      if (branch_taken) {
          goto L_08B62BF0;
      }
      goto L_08B62BE8;
    }
L_08B62BE4:
    // nop
    goto L_08B62BE8;
L_08B62BE8:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62CA8;
      }
      goto L_08B62BF0;
    }
L_08B62BEC:
    // nop
    goto L_08B62BF0;
L_08B62BF0:
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(ctx.gpr[16] + static_cast<std::uint32_t>(966))))));
    goto L_08B62BF4;
L_08B62BF4:
    ctx.gpr[6] = (static_cast<std::int32_t>(ctx.gpr[5]) < 7 ? 1u : 0u);
    goto L_08B62BF8;
L_08B62BF8:
    { const bool branch_taken = ctx.gpr[6] == 0u;
    ctx.gpr[4] = (0u + static_cast<std::uint32_t>(-1));
      if (branch_taken) {
          goto L_08B62C14;
      }
      goto L_08B62C00;
    }
L_08B62BFC:
    ctx.gpr[4] = (0u + static_cast<std::uint32_t>(-1));
    goto L_08B62C00;
L_08B62C00:
    ctx.gpr[5] = (static_cast<std::int32_t>(ctx.gpr[5]) < 6 ? 1u : 0u);
    goto L_08B62C04;
L_08B62C04:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    // nop
      if (branch_taken) {
          goto L_08B62C20;
      }
      goto L_08B62C0C;
    }
L_08B62C08:
    // nop
    goto L_08B62C0C;
L_08B62C0C:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[4] = (0u | 20u);
      if (branch_taken) {
          goto L_08B62C20;
      }
      goto L_08B62C14;
    }
L_08B62C10:
    ctx.gpr[4] = (0u | 20u);
    goto L_08B62C14;
L_08B62C14:
    { const bool branch_taken = ctx.gpr[5] != ctx.gpr[20];
    // nop
      if (branch_taken) {
          goto L_08B62C20;
      }
      goto L_08B62C1C;
    }
L_08B62C18:
    // nop
    goto L_08B62C1C;
L_08B62C1C:
    ctx.gpr[4] = (ctx.gpr[20] | 0u);
    goto L_08B62C20;
L_08B62C20:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[4]) >= 0;
    // nop
      if (branch_taken) {
          goto L_08B62C30;
      }
      goto L_08B62C28;
    }
L_08B62C24:
    // nop
    goto L_08B62C28;
L_08B62C28:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62CA8;
      }
      goto L_08B62C30;
    }
L_08B62C2C:
    // nop
    goto L_08B62C30;
L_08B62C30:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[21] + static_cast<std::uint32_t>(27360)));
    goto L_08B62C34;
L_08B62C34:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(8)));
    goto L_08B62C38;
L_08B62C38:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    // nop
      if (branch_taken) {
          goto L_08B62C48;
      }
      goto L_08B62C40;
    }
L_08B62C3C:
    // nop
    goto L_08B62C40;
L_08B62C40:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62CA8;
      }
      goto L_08B62C48;
    }
L_08B62C44:
    // nop
    goto L_08B62C48;
L_08B62C48:
    ctx.gpr[6] = (ctx.gpr[4] | 0u);
    goto L_08B62C4C;
L_08B62C4C:
    ctx.gpr[4] = (ctx.gpr[5] | 0u);
    goto L_08B62C50;
L_08B62C50:
    ctx.gpr[5] = (ctx.gpr[6] | 0u);
    goto L_08B62C54;
L_08B62C54:
    ctx.gpr[6] = (0u | 0u);
    goto L_08B62C58;
L_08B62C58:
    ctx.gpr[7] = (0u | 0u);
    goto L_08B62C5C;
L_08B62C5C:
    ctx.gpr[31] = (0x08B62C64u);
    ctx.gpr[8] = (0u | 0u);
    ctx.pc = 0x088A9DE8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62C64u) goto L_08B62C64;
    return;
L_08B62C60:
    ctx.gpr[8] = (0u | 0u);
    goto L_08B62C64;
L_08B62C64:
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
    goto L_08B62C68;
L_08B62C68:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.gpr[5] = (ctx.gpr[16] + static_cast<std::uint32_t>(128));
      if (branch_taken) {
          goto L_08B62C78;
      }
      goto L_08B62C70;
    }
L_08B62C6C:
    ctx.gpr[5] = (ctx.gpr[16] + static_cast<std::uint32_t>(128));
    goto L_08B62C70;
L_08B62C70:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62CA8;
      }
      goto L_08B62C78;
    }
L_08B62C74:
    // nop
    goto L_08B62C78;
L_08B62C78:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    goto L_08B62C7C;
L_08B62C7C:
    ctx.fpr[22] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    goto L_08B62C80;
L_08B62C80:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62C84;
L_08B62C84:
    ctx.fpr[24] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(8)));
    goto L_08B62C88;
L_08B62C88:
    ctx.fpr[22] = ctx.fpr[22] + ctx.fpr[28];
    goto L_08B62C8C;
L_08B62C8C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[6]);
    goto L_08B62C90;
L_08B62C90:
    ctx.fpr[26] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(12)));
    goto L_08B62C94;
L_08B62C94:
    ctx.fpr[14] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[24]));
    goto L_08B62C98;
L_08B62C98:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B62C9C;
L_08B62C9C:
    ctx.gpr[31] = (0x08B62CA4u);
    ctx.fpr[13] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    ctx.pc = 0x088A7284u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62CA4u) goto L_08B62CA4;
    return;
L_08B62CA0:
    ctx.fpr[13] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B62CA4;
L_08B62CA4:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4368), std::bit_cast<std::uint32_t>(ctx.fpr[30]));
    goto L_08B62CA8;
L_08B62CA8:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B62B58;
      }
      goto L_08B62CB0;
    }
L_08B62CAC:
    // nop
    goto L_08B62CB0;
L_08B62CB0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[24]));
    goto L_08B62CB4;
L_08B62CB4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[26]));
    goto L_08B62CB8;
L_08B62CB8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B62CBC;
L_08B62CBC:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(16)));
    goto L_08B62CC0;
L_08B62CC0:
    ctx.fpr[22] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(20)));
    goto L_08B62CC4;
L_08B62CC4:
    ctx.fpr[24] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(24)));
    goto L_08B62CC8;
L_08B62CC8:
    ctx.fpr[26] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(28)));
    goto L_08B62CCC;
L_08B62CCC:
    ctx.fpr[28] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(32)));
    goto L_08B62CD0;
L_08B62CD0:
    ctx.fpr[30] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(36)));
    goto L_08B62CD4;
L_08B62CD4:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(40)));
    goto L_08B62CD8;
L_08B62CD8:
    ctx.gpr[17] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(44)));
    goto L_08B62CDC;
L_08B62CDC:
    ctx.gpr[18] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(48)));
    goto L_08B62CE0;
L_08B62CE0:
    ctx.gpr[19] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(52)));
    goto L_08B62CE4;
L_08B62CE4:
    ctx.gpr[20] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(56)));
    goto L_08B62CE8;
L_08B62CE8:
    ctx.gpr[21] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(60)));
    goto L_08B62CEC;
L_08B62CEC:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(64)));
    goto L_08B62CF0;
L_08B62CF0:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(80));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B62CF4:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(80));
    goto L_08B62CF8;
L_08B62CF8:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-80));
    goto L_08B62CFC;
L_08B62CFC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(48), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B62D00;
L_08B62D00:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(52), std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B62D04;
L_08B62D04:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(56), ctx.gpr[16]);
    goto L_08B62D08;
L_08B62D08:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(60), ctx.gpr[17]);
    goto L_08B62D0C;
L_08B62D0C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(64), ctx.gpr[18]);
    goto L_08B62D10;
L_08B62D10:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(68), ctx.gpr[31]);
    goto L_08B62D14;
L_08B62D14:
    ctx.gpr[31] = (0x08B62D1Cu);
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
    ctx.pc = 0x08842164u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62D1Cu) goto L_08B62D1C;
    return;
L_08B62D18:
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
    goto L_08B62D1C;
L_08B62D1C:
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
    goto L_08B62D20;
L_08B62D20:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(128));
      if (branch_taken) {
          goto L_08B62D5C;
      }
      goto L_08B62D28;
    }
L_08B62D24:
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(128));
    goto L_08B62D28;
L_08B62D28:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    goto L_08B62D2C;
L_08B62D2C:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B62D30;
L_08B62D30:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(8)));
    goto L_08B62D34;
L_08B62D34:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62D38;
L_08B62D38:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(12)));
    goto L_08B62D3C;
L_08B62D3C:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B62D40;
L_08B62D40:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(0), ctx.gpr[5]);
    goto L_08B62D44;
L_08B62D44:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B62D48;
L_08B62D48:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4), ctx.gpr[6]);
    goto L_08B62D4C;
L_08B62D4C:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[15]));
    goto L_08B62D50;
L_08B62D50:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(8), ctx.gpr[4]);
    goto L_08B62D54;
L_08B62D54:
    { const bool branch_taken = 0u == 0u;
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(12), ctx.gpr[5]);
      if (branch_taken) {
          goto L_08B62E90;
      }
      goto L_08B62D5C;
    }
L_08B62D58:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(12), ctx.gpr[5]);
    goto L_08B62D5C;
L_08B62D5C:
    ctx.gpr[4] = (2205u << 16u);
    goto L_08B62D60;
L_08B62D60:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(24256)));
    goto L_08B62D64;
L_08B62D64:
    ctx.gpr[18] = (ctx.gpr[4] + static_cast<std::uint32_t>(2016));
    goto L_08B62D68;
L_08B62D68:
    ctx.gpr[17] = (ctx.gpr[4] + static_cast<std::uint32_t>(1824));
    goto L_08B62D6C;
L_08B62D6C:
    ctx.gpr[31] = (0x08B62D74u);
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    ctx.pc = 0x0885EA90u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62D74u) goto L_08B62D74;
    return;
L_08B62D70:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B62D74;
L_08B62D74:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(0)));
    goto L_08B62D78;
L_08B62D78:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(4)));
    goto L_08B62D7C;
L_08B62D7C:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(8)));
    goto L_08B62D80;
L_08B62D80:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62D84;
L_08B62D84:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(12)));
    goto L_08B62D88;
L_08B62D88:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B62D8C;
L_08B62D8C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    goto L_08B62D90;
L_08B62D90:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B62D94;
L_08B62D94:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[5]);
    goto L_08B62D98;
L_08B62D98:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[15]));
    goto L_08B62D9C;
L_08B62D9C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[6]);
    goto L_08B62DA0;
L_08B62DA0:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[4]);
    goto L_08B62DA4;
L_08B62DA4:
    ctx.gpr[31] = (0x08B62DACu);
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    ctx.pc = 0x0885EA98u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62DACu) goto L_08B62DAC;
    return;
L_08B62DA8:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B62DAC;
L_08B62DAC:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(0)));
    goto L_08B62DB0;
L_08B62DB0:
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(4)));
    goto L_08B62DB4;
L_08B62DB4:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(8)));
    goto L_08B62DB8;
L_08B62DB8:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62DBC;
L_08B62DBC:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(12)));
    goto L_08B62DC0;
L_08B62DC0:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    goto L_08B62DC4;
L_08B62DC4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[4]);
    goto L_08B62DC8;
L_08B62DC8:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_08B62DCC;
L_08B62DCC:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[5]);
    goto L_08B62DD0;
L_08B62DD0:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    goto L_08B62DD4;
L_08B62DD4:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[6]);
    goto L_08B62DD8;
L_08B62DD8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), ctx.gpr[4]);
    goto L_08B62DDC;
L_08B62DDC:
    ctx.gpr[31] = (0x08B62DE4u);
    ctx.gpr[4] = (ctx.gpr[18] | 0u);
    ctx.pc = 0x0887357Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62DE4u) goto L_08B62DE4;
    return;
L_08B62DE0:
    ctx.gpr[4] = (ctx.gpr[18] | 0u);
    goto L_08B62DE4;
L_08B62DE4:
    ctx.gpr[17] = (ctx.gpr[29] + static_cast<std::uint32_t>(32));
    goto L_08B62DE8;
L_08B62DE8:
    ctx.fpr[20] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[0]));
    goto L_08B62DEC;
L_08B62DEC:
    ctx.gpr[5] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    goto L_08B62DF0;
L_08B62DF0:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B62DF4;
L_08B62DF4:
    ctx.gpr[31] = (0x08B62DFCu);
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    ctx.pc = 0x089A38FCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62DFCu) goto L_08B62DFC;
    return;
L_08B62DF8:
    ctx.gpr[6] = (ctx.gpr[29] | 0u);
    goto L_08B62DFC;
L_08B62DFC:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B62E00;
L_08B62E00:
    ctx.gpr[31] = (0x08B62E08u);
    ctx.gpr[5] = (ctx.gpr[17] | 0u);
    ctx.pc = 0x089A3BC8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62E08u) goto L_08B62E08;
    return;
L_08B62E04:
    ctx.gpr[5] = (ctx.gpr[17] | 0u);
    goto L_08B62E08;
L_08B62E08:
    ctx.gpr[4] = (2230u << 16u);
    goto L_08B62E0C;
L_08B62E0C:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(11984)));
    goto L_08B62E10;
L_08B62E10:
    ctx.gpr[4] = (16128u << 16u);
    goto L_08B62E14;
L_08B62E14:
    ctx.fpr[22] = std::bit_cast<float>(ctx.gpr[4]);
    goto L_08B62E18;
L_08B62E18:
    ctx.gpr[5] = (ctx.gpr[17] | 0u);
    goto L_08B62E1C;
L_08B62E1C:
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B62E20;
L_08B62E20:
    ctx.gpr[4] = (ctx.gpr[17] | 0u);
    goto L_08B62E24;
L_08B62E24:
    ctx.gpr[31] = (0x08B62E2Cu);
    ctx.fpr[12] = ctx.fpr[20] + ctx.fpr[12];
    ctx.pc = 0x089A3A64u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62E2Cu) goto L_08B62E2C;
    return;
L_08B62E28:
    ctx.fpr[12] = ctx.fpr[20] + ctx.fpr[12];
    goto L_08B62E2C;
L_08B62E2C:
    ctx.gpr[4] = (ctx.gpr[29] | 0u);
    goto L_08B62E30;
L_08B62E30:
    ctx.gpr[5] = (ctx.gpr[29] | 0u);
    goto L_08B62E34;
L_08B62E34:
    ctx.gpr[31] = (0x08B62E3Cu);
    ctx.gpr[6] = (ctx.gpr[17] | 0u);
    ctx.pc = 0x089A38C4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B62E3Cu) goto L_08B62E3C;
    return;
L_08B62E38:
    ctx.gpr[6] = (ctx.gpr[17] | 0u);
    goto L_08B62E3C;
L_08B62E3C:
    ctx.gpr[4] = (2230u << 16u);
    goto L_08B62E40;
L_08B62E40:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(11992)));
    goto L_08B62E44;
L_08B62E44:
    ctx.gpr[4] = (2230u << 16u);
    goto L_08B62E48;
L_08B62E48:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(11988)));
    goto L_08B62E4C;
L_08B62E4C:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B62E50;
L_08B62E50:
    ctx.fpr[12] = ctx.fpr[12] - ctx.fpr[13];
    goto L_08B62E54;
L_08B62E54:
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B62E58;
L_08B62E58:
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08B62E5C;
L_08B62E5C:
    ctx.fpr[17] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(12)));
    goto L_08B62E60;
L_08B62E60:
    ctx.gpr[4] = (std::bit_cast<std::uint32_t>(ctx.fpr[15]));
    goto L_08B62E64;
L_08B62E64:
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    goto L_08B62E68;
L_08B62E68:
    ctx.gpr[5] = (std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    goto L_08B62E6C;
L_08B62E6C:
    ctx.gpr[6] = (std::bit_cast<std::uint32_t>(ctx.fpr[17]));
    goto L_08B62E70;
L_08B62E70:
    ctx.fpr[12] = ctx.fpr[14] - ctx.fpr[12];
    goto L_08B62E74;
L_08B62E74:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62E78;
L_08B62E78:
    ctx.gpr[7] = (std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_08B62E7C;
L_08B62E7C:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    goto L_08B62E80;
L_08B62E80:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4), ctx.gpr[7]);
    goto L_08B62E84;
L_08B62E84:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(8), ctx.gpr[5]);
    goto L_08B62E88;
L_08B62E88:
    { const bool branch_taken = 0u == 0u;
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(12), ctx.gpr[6]);
      if (branch_taken) {
          goto L_08B62E90;
      }
      goto L_08B62E90;
    }
L_08B62E8C:
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(12), ctx.gpr[6]);
    goto L_08B62E90;
L_08B62E90:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(48)));
    goto L_08B62E94;
L_08B62E94:
    ctx.fpr[22] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(52)));
    goto L_08B62E98;
L_08B62E98:
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(56)));
    goto L_08B62E9C;
L_08B62E9C:
    ctx.gpr[17] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(60)));
    goto L_08B62EA0;
L_08B62EA0:
    ctx.gpr[18] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(64)));
    goto L_08B62EA4;
L_08B62EA4:
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(68)));
    goto L_08B62EA8;
L_08B62EA8:
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(80));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B62EAC:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(80));
    goto L_08B62EB0;
L_08B62EB0:
    rt.unsupported(0x08B62EB0u, 0x7F7FFFFFu, "special3? not lowered yet"); return;
L_08B62EB4:
    rt.unsupported(0x08B62EB4u, 0x41A00000u, "unknown not lowered yet"); return;
L_08B62EB8:
    rt.unsupported(0x08B62EB8u, 0x42200000u, "unknown not lowered yet"); return;
L_08B62EBC:
    rt.unsupported(0x08B62EBCu, 0x40400000u, "unknown not lowered yet"); return;
L_08B62EC0:
    ctx.gpr[12] = (52429u << 16u);
    goto L_08B62EC4;
L_08B62EC4:
    rt.unsupported(0x08B62EC4u, 0x41F00000u, "unknown not lowered yet"); return;
L_08B62EC8:
    rt.unsupported(0x08B62EC8u, 0x42480000u, "unknown not lowered yet"); return;
L_08B62ECC:
    rt.execute_extra_instruction(ctx, 0x08B62ECCu, 0xC1200000u);
    goto L_08B62ED0;
L_08B62ED0:
    rt.unsupported(0x08B62ED0u, 0x41200000u, "unknown not lowered yet"); return;
L_08B62ED4:
    // nop
    goto L_08B62ED8;
L_08B62ED8:
    rt.unsupported(0x08B62ED8u, 0x41200000u, "unknown not lowered yet"); return;
L_08B62EDC:
    rt.execute_extra_instruction(ctx, 0x08B62EDCu, 0xC1200000u);
    goto L_08B62EE0;
L_08B62EE0:
    rt.unsupported(0x08B62EE0u, 0x41200000u, "unknown not lowered yet"); return;
L_08B62EE4:
    // PSP CACHE is a no-op in coherent host memory.
    goto L_08B62EE8;
L_08B62EE8:
    ctx.gpr[12] = (52429u << 16u);
    goto L_08B62EEC;
L_08B62EEC:
    // PSP CACHE is a no-op in coherent host memory.
    goto L_08B62EF0;
L_08B62EF0:
    // PSP CACHE is a no-op in coherent host memory.
    goto L_08B62EF4;
L_08B62EF4:
    // PSP CACHE is a no-op in coherent host memory.
    goto L_08B62EF8;
L_08B62EF8:
    ctx.gpr[12] = (52429u << 16u);
    goto L_08B62EFC;
L_08B62EFC:
    rt.unsupported(0x08B62EFCu, 0x41200000u, "unknown not lowered yet"); return;
L_08B62F00:
    ctx.gpr[13] = (ctx.gpr[3] ^ ctx.gpr[7]);
    goto L_08B62F04;
L_08B62F04:
    // nop
    goto L_08B62F08;
L_08B62F08:
    rt.unsupported(0x08B62F0Cu, 0x08A4D810u, "control flow in delay slot"); return;
L_08B62F0C:
    rt.unsupported(0x08B62F10u, 0x08AC3EDCu, "control flow in delay slot"); return;
L_08B62F10:
    rt.unsupported(0x08B62F14u, 0x08ADCEB0u, "control flow in delay slot"); return;
L_08B62F14:
    rt.unsupported(0x08B62F18u, 0x08AE0138u, "control flow in delay slot"); return;
L_08B62F18:
    rt.unsupported(0x08B62F1Cu, 0x08AE7B3Cu, "control flow in delay slot"); return;
L_08B62F1C:
    rt.unsupported(0x08B62F20u, 0x08AEA818u, "control flow in delay slot"); return;
L_08B62F20:
    rt.unsupported(0x08B62F24u, 0x08AEB978u, "control flow in delay slot"); return;
L_08B62F24:
    rt.unsupported(0x08B62F28u, 0x08AECB98u, "control flow in delay slot"); return;
L_08B62F28:
    rt.unsupported(0x08B62F2Cu, 0x08AEED04u, "control flow in delay slot"); return;
L_08B62F2C:
    rt.unsupported(0x08B62F30u, 0x08AEF1C0u, "control flow in delay slot"); return;
L_08B62F30:
    rt.unsupported(0x08B62F34u, 0x08AF0944u, "control flow in delay slot"); return;
L_08B62F34:
    rt.unsupported(0x08B62F38u, 0x08AFCAA4u, "control flow in delay slot"); return;
L_08B62F38:
    rt.unsupported(0x08B62F3Cu, 0x08B00008u, "control flow in delay slot"); return;
L_08B62F3C:
    rt.unsupported(0x08B62F40u, 0x08B12594u, "control flow in delay slot"); return;
L_08B62F40:
    rt.unsupported(0x08B62F44u, 0x08B277F8u, "control flow in delay slot"); return;
L_08B62F44:
    rt.unsupported(0x08B62F48u, 0x08B3A968u, "control flow in delay slot"); return;
L_08B62F48:
    rt.unsupported(0x08B62F4Cu, 0x08B516ECu, "control flow in delay slot"); return;
L_08B62F4C:
    rt.unsupported(0x08B62F50u, 0x08B542A4u, "control flow in delay slot"); return;
L_08B62F50:
    rt.unsupported(0x08B62F54u, 0x08B59CD0u, "control flow in delay slot"); return;
L_08B62F54:
    rt.unsupported(0x08B62F58u, 0x08B5ECF8u, "control flow in delay slot"); return;
L_08B62F58:
    rt.unsupported(0x08B62F5Cu, 0x08A4AAD0u, "control flow in delay slot"); return;
L_08B62F5C:
    rt.unsupported(0x08B62F60u, 0x08A4AADCu, "control flow in delay slot"); return;
L_08B62F60:
    rt.unsupported(0x08B62F64u, 0x08A4DA80u, "control flow in delay slot"); return;
L_08B62F64:
    rt.unsupported(0x08B62F68u, 0x08A4DA8Cu, "control flow in delay slot"); return;
L_08B62F68:
    rt.unsupported(0x08B62F6Cu, 0x08B125CCu, "control flow in delay slot"); return;
L_08B62F6C:
    // nop
    ctx.pc = 0x02C49730u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
}

void ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097(CorpusRuntime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097_entry(rt, ctx, 0u, aot_mem);
}

void register_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_97(CorpusRuntime &runtime) {
    runtime.register_function(0x08B614C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B614FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61500u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61504u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61508u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6150Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61510u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61514u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61518u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6151Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61520u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61524u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61528u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6152Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61530u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61534u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61538u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6153Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61540u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61544u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61548u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6154Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61550u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61554u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61558u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6155Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61560u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61564u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61568u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6156Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61570u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61574u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61578u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6157Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61580u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61584u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61588u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6158Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61590u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61594u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61598u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6159Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B615FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61600u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61604u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61608u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6160Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61610u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61614u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61618u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6161Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61620u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61624u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61628u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6162Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61630u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61634u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61638u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6163Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61640u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61644u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61648u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6164Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61650u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61654u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61658u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6165Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61660u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61664u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61668u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6166Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61670u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61674u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61678u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6167Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61680u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61684u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61688u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6168Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61690u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61694u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61698u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6169Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B616FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61700u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61704u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61708u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6170Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61710u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61714u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61718u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6171Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61720u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61724u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61728u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6172Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61730u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61734u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61738u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6173Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61740u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61744u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61748u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6174Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61750u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61754u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61758u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6175Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61760u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61764u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61768u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6176Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61770u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61774u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61778u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6177Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61780u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61784u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61788u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6178Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61790u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61794u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61798u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6179Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B617FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61800u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61804u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61808u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6180Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61810u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61814u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61818u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6181Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61820u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61824u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61828u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6182Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61830u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61834u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61838u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6183Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61840u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61844u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61848u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6184Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61850u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61854u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61858u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6185Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61860u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61864u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61868u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6186Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61870u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61874u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61878u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6187Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61880u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61884u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61888u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6188Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61890u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61894u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61898u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6189Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B618FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61900u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61904u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61908u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6190Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61910u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61914u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61918u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6191Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61920u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61924u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61928u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6192Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61930u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61934u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61938u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6193Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61940u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61944u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61948u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6194Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61950u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61954u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61958u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6195Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61960u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61964u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61968u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6196Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61970u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61974u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61978u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6197Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61980u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61984u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61988u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6198Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61990u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61994u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61998u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6199Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B619FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A70u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A74u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A78u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A7Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A80u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A84u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A88u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A8Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A90u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A94u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A98u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61A9Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AA0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AA4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AA8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AB0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AB4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AB8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61ABCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AC0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AC4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AC8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61ACCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AD0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AD4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AD8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61ADCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AE0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AE4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AE8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AF0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AF4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AF8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61AFCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B70u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B74u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B78u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B7Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B80u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B84u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B88u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B8Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B90u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B94u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B98u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61B9Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BA0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BA4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BA8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BB0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BB4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BB8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BBCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BC0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BC4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BC8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BCCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BD0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BD4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BD8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BDCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BE0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BE4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BE8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BF0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BF4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BF8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61BFCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C70u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C74u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C78u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C7Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C80u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C84u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C88u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C8Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C90u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C94u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C98u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61C9Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CA0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CA4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CA8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CB0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CB4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CB8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CBCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CC0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CC4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CC8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CCCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CD0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CD4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CD8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CDCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CE0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CE4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CE8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CF0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CF4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CF8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61CFCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D70u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D74u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D78u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D7Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D80u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D84u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D88u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D8Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D90u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D94u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D98u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61D9Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DA0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DA4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DA8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DB0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DB4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DB8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DBCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DC0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DC4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DC8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DCCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DD0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DD4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DD8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DDCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DE0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DE4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DE8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DF0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DF4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DF8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61DFCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E70u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E74u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E78u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E7Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E80u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E84u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E88u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E8Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E90u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E94u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E98u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61E9Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EA0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EA4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EA8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EB0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EB4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EB8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EBCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EC0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EC4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EC8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61ECCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61ED0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61ED4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61ED8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EDCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EE0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EE4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EE8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EF0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EF4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EF8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61EFCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F70u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F74u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F78u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F7Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F80u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F84u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F88u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F8Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F90u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F94u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F98u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61F9Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FA0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FA4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FA8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FB0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FB4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FB8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FBCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FC0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FC4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FC8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FCCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FD0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FD4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FD8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FDCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FE0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FE4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FE8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FF0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FF4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FF8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B61FFCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62000u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62004u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62008u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6200Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62010u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62014u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62018u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6201Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62020u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62024u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62028u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6202Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62030u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62034u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62038u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6203Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62040u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62044u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62048u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6204Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62050u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62054u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62058u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6205Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62060u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62064u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62068u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6206Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62070u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62074u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62078u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6207Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62080u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62084u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62088u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6208Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62090u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62094u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62098u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6209Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B620FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62100u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62104u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62108u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6210Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62110u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62114u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62118u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6211Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62120u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62124u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62128u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6212Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62130u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62134u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62138u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6213Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62140u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62144u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62148u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6214Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62150u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62154u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62158u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6215Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62160u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62164u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62168u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6216Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62170u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62174u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62178u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6217Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62180u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62184u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62188u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6218Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62190u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62194u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62198u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6219Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B621FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62200u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62204u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62208u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6220Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62210u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62214u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62218u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6221Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62220u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62224u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62228u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6222Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62230u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62234u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62238u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6223Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62240u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62244u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62248u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6224Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62250u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62254u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62258u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6225Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62260u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62264u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62268u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6226Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62270u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62274u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62278u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6227Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62280u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62284u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62288u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6228Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62290u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62294u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62298u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6229Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B622FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62300u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62304u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62308u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6230Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62310u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62314u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62318u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6231Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62320u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62324u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62328u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6232Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62330u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62334u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62338u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6233Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62340u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62344u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62348u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6234Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62350u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62354u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62358u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6235Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62360u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62364u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62368u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6236Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62370u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62374u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62378u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6237Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62380u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62384u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62388u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6238Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62390u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62394u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62398u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6239Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B623FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62400u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62404u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62408u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6240Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62410u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62414u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62418u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6241Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62420u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62424u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62428u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6242Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62430u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62434u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62438u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6243Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62440u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62444u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62448u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6244Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62450u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62454u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62458u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6245Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62460u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62464u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62468u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6246Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62470u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62474u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62478u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6247Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62480u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62484u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62488u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6248Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62490u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62494u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62498u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6249Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B624FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62500u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62504u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62508u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6250Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62510u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62514u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62518u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6251Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62520u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62524u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62528u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6252Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62530u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62534u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62538u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6253Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62540u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62544u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62548u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6254Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62550u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62554u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62558u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6255Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62560u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62564u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62568u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6256Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62570u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62574u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62578u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6257Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62580u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62584u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62588u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6258Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62590u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62594u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62598u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6259Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B625FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62600u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62604u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62608u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6260Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62610u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62614u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62618u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6261Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62620u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62624u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62628u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6262Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62630u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62634u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62638u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6263Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62640u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62644u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62648u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6264Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62650u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62654u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62658u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6265Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62660u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62664u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62668u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6266Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62670u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62674u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62678u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6267Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62680u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62684u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62688u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6268Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62690u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62694u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62698u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6269Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B626FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62700u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62704u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62708u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6270Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62710u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62714u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62718u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6271Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62720u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62724u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62728u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6272Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62730u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62734u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62738u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6273Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62740u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62744u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62748u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6274Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62750u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62754u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62758u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6275Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62760u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62764u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62768u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6276Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62770u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62774u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62778u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6277Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62780u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62784u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62788u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6278Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62790u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62794u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62798u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6279Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B627FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62800u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62804u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62808u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6280Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62810u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62814u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62818u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6281Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62820u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62824u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62828u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6282Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62830u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62834u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62838u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6283Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62840u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62844u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62848u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6284Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62850u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62854u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62858u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6285Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62860u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62864u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62868u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6286Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62870u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62874u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62878u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6287Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62880u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62884u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62888u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6288Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62890u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62894u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62898u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6289Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B628FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62900u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62904u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62908u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6290Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62910u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62914u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62918u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6291Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62920u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62924u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62928u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6292Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62930u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62934u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62938u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6293Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62940u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62944u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62948u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6294Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62950u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62954u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62958u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6295Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62960u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62964u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62968u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6296Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62970u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62974u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62978u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6297Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62980u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62984u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62988u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6298Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62990u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62994u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62998u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B6299Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629A0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629A4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629A8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629ACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629B0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629B4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629B8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629BCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629C0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629C4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629C8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629CCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629D0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629D4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629D8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629DCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629E0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629E4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629E8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629ECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629F0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629F4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629F8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B629FCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A70u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A74u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A78u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A7Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A80u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A84u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A88u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A8Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A90u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A94u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A98u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62A9Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AA0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AA4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AA8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AB0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AB4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AB8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62ABCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AC0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AC4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AC8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62ACCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AD0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AD4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AD8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62ADCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AE0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AE4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AE8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AF0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AF4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AF8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62AFCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B70u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B74u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B78u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B7Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B80u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B84u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B88u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B8Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B90u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B94u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B98u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62B9Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BA0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BA4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BA8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BB0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BB4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BB8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BBCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BC0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BC4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BC8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BCCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BD0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BD4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BD8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BDCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BE0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BE4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BE8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BF0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BF4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BF8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62BFCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C70u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C74u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C78u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C7Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C80u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C84u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C88u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C8Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C90u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C94u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C98u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62C9Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CA0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CA4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CA8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CB0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CB4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CB8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CBCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CC0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CC4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CC8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CCCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CD0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CD4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CD8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CDCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CE0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CE4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CE8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CF0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CF4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CF8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62CFCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D70u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D74u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D78u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D7Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D80u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D84u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D88u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D8Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D90u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D94u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D98u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62D9Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DA0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DA4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DA8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DB0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DB4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DB8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DBCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DC0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DC4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DC8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DCCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DD0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DD4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DD8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DDCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DE0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DE4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DE8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DF0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DF4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DF8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62DFCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E70u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E74u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E78u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E7Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E80u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E84u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E88u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E8Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E90u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E94u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E98u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62E9Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EA0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EA4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EA8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EACu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EB0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EB4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EB8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EBCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EC0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EC4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EC8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62ECCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62ED0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62ED4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62ED8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EDCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EE0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EE4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EE8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EECu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EF0u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EF4u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EF8u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62EFCu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F00u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F04u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F08u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F0Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F10u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F14u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F18u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F1Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F20u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F24u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F28u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F2Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F30u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F34u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F38u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F3Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F40u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F44u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F48u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F4Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F50u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F54u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F58u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F5Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F60u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F64u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F68u, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
    runtime.register_function(0x08B62F6Cu, &ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097, "recomp_unit_ovl089DD4C0_battle_A3D8F60BD768B4A8_unit_0097");
}
} // namespace psprecomp
