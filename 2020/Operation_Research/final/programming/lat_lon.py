import math
from math import sin, asin, cos, radians, fabs, sqrt

def get_factory_data():
    data = {}
    with open('fac.csv') as fr:
        raw = fr.readlines()
        for line in raw:
            line = line.strip()
            co_name, loc, lat, long = line.split(',')
            latitiude = float(lat.strip())
            longitude = float(long.strip())

            data[co_name] = (latitiude, longitude)
    return data

def get_district_data():
    data = {}
    with open('dis_ll.csv') as fr:
        raw = fr.readlines()
        for line in raw:
            line = line.strip()
            district, long, lat = line.split(',')
            latitiude = float(lat.strip())
            longitude = float(long.strip())

            data[district] = (latitiude, longitude)
    return data

def get_distance(latA, lonA, latB, lonB):
    '''
        Calculate distance btw two points(latA, lonA, latB, lonB), in meters
    '''
    ra = 6378140  # radius of equator: meter
    rb = 6356755  # radius of polar: meter
    flatten = (ra - rb) / ra  # Partial rate of the earth
    # change angle to radians
    radLatA = math.radians(latA)
    radLonA = math.radians(lonA)
    radLatB = math.radians(latB)
    radLonB = math.radians(lonB)

    pA = math.atan(rb / ra * math.tan(radLatA))
    pB = math.atan(rb / ra * math.tan(radLatB))

    input = math.sin(pA) * math.sin(pB) + math.cos(pA) * math.cos(pB) * math.cos(radLonA - radLonB)
    input = -1 if input < -1 else input
    input = 1 if input > 1 else input
    x = math.acos(input)

    c1 = (math.sin(x) - x) * (math.sin(pA) + math.sin(pB))**2 / math.cos(x / 2)**2
    try:
        c2 = (math.sin(x) + x) * (math.sin(pA) - math.sin(pB))**2 / math.sin(x / 2)**2
    except:
        c2 = 0

    dr = flatten / 8 * (c1 - c2)
    distance = ra * (x + dr)
    return distance

def distance(lat1, lon1, lat2, lon2):
    radius = 6371 # km

    dlat = math.radians(lat2-lat1)
    dlon = math.radians(lon2-lon1)
    a = math.sin(dlat/2) * math.sin(dlat/2) + math.cos(math.radians(lat1)) \
        * math.cos(math.radians(lat2)) * math.sin(dlon/2) * math.sin(dlon/2)
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
    d = radius * c

    return d

def haversine(lon1, lat1, lon2, lat2): # 经度1，纬度1，经度2，纬度2 （十进制度数）
    """
    Calculate the great circle distance between two points
    on the earth (specified in decimal degrees)
    """
    # 将十进制度数转化为弧度
    lon1, lat1, lon2, lat2 = map(radians, [lon1, lat1, lon2, lat2])

    # haversine公式
    dlon = lon2 - lon1
    dlat = lat2 - lat1
    a = sin(dlat/2)**2 + cos(lat1) * cos(lat2) * sin(dlon/2)**2
    c = 2 * asin(sqrt(a))
    r = 6371 # 地球平均半径，单位为公里
    return c * r * 1000

district_data = get_district_data()
factory_data = get_factory_data()

distance_dis_fac = {}

for dis in district_data:
    print(f"==========================================================\nDistrict: {dis}\n")
    distance_dis_fac[dis] = {}

    # get district's latitude and longitude
    dis_lat, dis_lon = district_data[dis]
    for fac in factory_data:
        # get factory's latitude and longitude
        fac_lon, fac_lat = factory_data[fac]

        distance_dis_fac[dis][fac] = get_distance(dis_lat, dis_lon, fac_lat, fac_lon)
        temp_dis = distance(dis_lat, dis_lon, fac_lat, fac_lon)
        haver = haversine(dis_lon, dis_lat, fac_lon, fac_lat)
        print(f"D_[{dis}, {fac}] = {distance_dis_fac[dis][fac]} versus {temp_dis} versus {haver} data = {dis_lat, dis_lon, fac_lat, fac_lon}")
