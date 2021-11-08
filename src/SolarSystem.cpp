#include"SolarSystem.h"

using namespace std;
// a - mean distance or semi major axis

// e - eccentricity

// T - time at perihelion

// q - perihelion distance = a *(1-e)

// i - inclination, i.e tilt of the orbit relative to the eliptic if > 180 degrees the body moves backwards

// N - longitude of ascending node, angle along the eliptic from the vernal point to the ascending node

// w - the angle from the ascending node tot he perihelion


// PRIMARY ORBITAL ELEMENTS

// q = a*(1-e)

// Q = a*(1+e)

// P (orbital period) = 365.256898326 * a**1.5/sqrt(1+m) days, where m = the mass 
// of the planet in solar masses (0 for comets and asteroids)

// n (daily motion) = 360_deg/P degrees/day

// t some epoch as a day count

// t -T time since perihelion in days

// M - Mean anomaly = n*(t-T) = (t-T)*360_deg/P

// L - Mean longitude = M + w + N

// E - eccentric anomaly M = E - e * sin(E)

// v - true anomaly

// r Heliocentric distance

// x,y,z rectangular coordinates. used when a heliocentric positions hould be converted

// this relation is a valid elliptic orbit:

// r * cos(v) = a * (cos(E) - e)
// r * sin(v) = a * sqrt(1-e*e) * sin(E)
                                       

SolarSystem::SolarSystem(int year,int month,int day,int hour,int minute){
    m_year = year;
    m_month = month;
    m_day = day;
    m_hour = hour;
    m_minute = minute;
}
void SolarSystem::computeTimeScale(){
    time_scale = 367*m_year - 7 * ( m_year + (m_month+9)/12 ) / 4 - 3 * ( (m_year + (m_month-9)/7 ) / 100 + 1 ) / 4 + 275*m_month/9 + m_day - 730515;
}

/**
 * 
 * 
 * 
 * def coordinates(year, month, day, hour, minute):

    d = time_scale

    // SUN POSITION

    // angle of ascending node (w)
    angle_asc = 282.9404 + 4.70935E-5 * d

    //essentricity (e) 
    eccentric = (0.016709 - (1.151E-9 * d))

    M
    m2 = normalize(356.047 + 0.9856002585 * d)

    m = math.radians(m2)
    e_capt = m2 + (180 / math.pi) * e * math.sin(m) * (1 + e * math.cos(m))
    e_capt = math.radians(e_capt)
    x = math.cos(e_capt) - e
    y = math.sin(e_capt) * math.sqrt(1 - e * e)

    r = math.sqrt(x * x + y * y)

    v = math.atan2(y, x)
    v = math.degrees(v)
    lon = (v + w)
    lon = normalize(lon)
    lon = math.radians(lon)
    x2 = r * math.cos(lon)
    y2 = r * math.sin(lon)

    earthX = -1 * x2
    earthY = -1 * y2
    earthZ = 0

    n_er = 48.3313 + 3.24587E-5 * d
    i_er = 7.0047 + 5.00E-8 * d
    w_er = 29.1241 + 1.01444E-5 * d
    a_er = 0.387098
    e_er = 0.205635 + 5.59E-10 * d
    m_er = 168.6562 + 4.0923344368 * d

    m_er = normalize(m_er)

    n_af = 76.6799 + 2.46590E-5 * d
    i_af = 3.3946 + 2.75E-8 * d
    w_af = 54.8910 + 1.38374E-5 * d
    a_af = 0.723330
    e_af = 0.006773 - 1.30E-9 * d
    m_af = 48.0052 + 1.6021302244 * d

    m_af = normalize(m_af)

    n_ar = 49.5574 + 2.11081E-5 * d
    i_ar = 1.8497 - 1.78E-8 * d
    w_ar = 286.5016 + 2.92961E-5 * d
    a_ar = 1.523688
    e_ar = 0.093405 + 2.51E-9 * d
    m_ar = 18.6021 + 0.5240207766 * d

    m_ar = normalize(m_ar)

    n_di = 100.4542 + 2.76854E-5 * d
    i_di = 1.3030 - 1.557E-7 * d
    w_di = 273.8777 + 1.6450E-5 * d
    a_di = 5.20256
    e_di = 0.048498 + 4.469E-9 * d
    m_di = 19.8950 + 0.0830853001 * d

    m_di = normalize(m_di)

    n_kr = 113.6634 + 2.38980E-5 * d
    i_kr = 2.4886 - 1.081E-7 * d
    w_kr = 339.3939 + 2.97661E-5 * d
    a_kr = 9.55475
    e_kr = 0.055546 - 9.499E-9 * d
    m_kr = 316.9670 + 0.0334442282 * d

    m_kr = normalize(m_kr)

    n_ou = 74.0005 + 1.3978E-5 * d
    i_ou = 0.7733 + 1.9E-8 * d
    w_ou = 96.6612 + 3.0565E-5 * d
    a_ou = 19.18171 - 1.55E-8 * d
    e_ou = 0.047318 + 7.45E-9 * d
    m_ou = 142.5905 + 0.011725806 * d

    m_ou = normalize(m_ou)

    n_po = 131.7806 + 3.0173E-5 * d
    i_po = 1.7700 - 2.55E-7 * d
    w_po = 272.8461 - 6.027E-6 * d
    a_po = 30.05826 + 3.313E-8 * d
    e_po = 0.008606 + 2.15E-9 * d
    m_po = 260.2471 + 0.005995147 * d

    m_po = normalize(m_po)
    xereclip, yereclip, zereclip, long2_er, lat2_er, r_er = from_sun(m_er,
                                                               e_er, a_er, n_er, w_er, i_er)
    xafeclip, yafeclip, zafeclip, long2_af, lat2_af, r_af = from_sun(m_af,
                                                                     e_af, a_af, n_af, w_af, i_af)
    xareclip, yareclip, zareclip, long2_ar, lat2_ar, r_ar = from_sun(m_ar,
                                                                     e_ar, a_ar, n_ar, w_ar, i_ar)
    xdieclip, ydieclip, zdieclip, long2_di, lat2_di, r_di = from_sun(m_di,
                                                                     e_di, a_di, n_di, w_di, i_di)
    xkreclip, ykreclip, zkreclip, long2_kr, lat2_kr, r_kr = from_sun(m_kr,
                                                                     e_kr, a_kr, n_kr, w_kr, i_kr)
    xoueclip, youeclip, zoueclip, long2_ou, lat2_ou, r_ou = from_sun(m_ou,
                                                                     e_ou, a_ou, n_ou, w_ou, i_ou)
    xpoeclip, ypoeclip, zpoeclip, long2_po, lat2_po, r_po = from_sun(m_po,
                                                                     e_po, a_po, n_po, w_po, i_po)
    m_di = normalize(m_di)
    m_kr = normalize(m_kr)
    m_ou = normalize(m_ou)

    di_diat1 = -0.332 * math.sin(math.radians(2 * m_di - 5 * m_kr - 67.6))
    di_diat2 = -0.056 * math.sin(math.radians(2 * m_di - 2 * m_kr + 21))
    di_diat3 = 0.042 * math.sin(math.radians(3 * m_di - 5 * m_kr + 21))
    di_diat4 = -0.036 * math.sin(math.radians(m_di - 2 * m_kr))
    di_diat5 = 0.022 * math.cos(math.radians(m_di - m_kr))
    di_diat6 = 0.023 * math.sin(math.radians(2 * m_di - 3 * m_kr + 52))
    di_diat7 = -0.016 * math.sin(math.radians(m_di - 5 * m_kr - 69))

    kr_diat1 = 0.812 * math.sin(math.radians(2 * m_di - 5 * m_kr - 67.6))
    kr_diat2 = -0.229 * math.cos(math.radians(2 * m_di - 4 * m_kr - 2))
    kr_diat3 = 0.119 * math.sin(math.radians(m_di - 2 * m_kr - 3))
    kr_diat4 = 0.046 * math.sin(math.radians(2 * m_di - 6 * m_kr - 69))
    kr_diat5 = 0.014 * math.sin(math.radians(m_di - 3 * m_kr + 32))

    kr_diat6 = -0.02 * math.cos(math.radians(2 * m_di - 4 * m_kr - 2))
    kr_diat7 = 0.018 * math.sin(math.radians(2 * m_di - 6 * m_kr - 49))

    ou_diat1 = 0.04 * math.sin(math.radians(m_kr - 2 * m_ou + 6))
    ou_diat2 = 0.035 * math.sin(math.radians(m_kr - 3 * m_ou + 33))
    ou_diat3 = -0.015 * math.sin(math.radians(m_di - m_ou + 20))

    diataraxes_long_di = (di_diat1 + di_diat2 + di_diat3 + di_diat4 +
                          di_diat5 + di_diat6 + di_diat7)
    diataraxes_long_kr = (kr_diat1 + kr_diat2 + kr_diat3 + kr_diat4
                          + kr_diat5)
    diataraxes_lat_kr = (kr_diat6 + kr_diat7)
    diataraxes_long_ou = (ou_diat1 + ou_diat2 + ou_diat3)

    long2_di = long2_di + diataraxes_long_di
    long2_kr = long2_kr + diataraxes_long_kr
    lat2_kr = lat2_kr + diataraxes_lat_kr
    long2_ou = long2_ou + diataraxes_long_ou

    long2_di = (math.radians(long2_di))
    lat2_di = (math.radians(lat2_di))
    long2_kr = (math.radians(long2_kr))
    lat2_kr = (math.radians(lat2_kr))
    long2_ou = (math.radians(long2_ou))
    lat2_ou = (math.radians(lat2_ou))

    xdieclip = r_di * math.cos(long2_di) * math.cos(lat2_di)
    ydieclip = r_di * math.sin(long2_di) * math.cos(lat2_di)
    zdieclip = r_di * math.sin(lat2_di)
    xkreclip = r_kr * math.cos(long2_kr) * math.cos(lat2_kr)
    ykreclip = r_kr * math.sin(long2_kr) * math.cos(lat2_kr)
    zkreclip = r_kr * math.sin(lat2_kr)
    xoueclip = r_ou * math.cos(long2_ou) * math.cos(lat2_ou)
    youeclip = r_ou * math.sin(long2_ou) * math.cos(lat2_ou)
    zoueclip = r_ou * math.sin(lat2_ou)

    return [(xereclip, yereclip, zereclip),  # Mercury
            (xafeclip, yafeclip, zafeclip),  # Venus
            (earthX, earthY, earthZ),        # Earth
            (xareclip, yareclip, zareclip),  # Mars
            (xdieclip, ydieclip, zdieclip),  # Jupiter
            (xkreclip, ykreclip, zkreclip),  # Saturn
            (xoueclip, youeclip, zoueclip),  # Uranus
            (xpoeclip, ypoeclip, zpoeclip)   # Neptune
            ]
            **/