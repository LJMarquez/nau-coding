import point

def main():
    point_one = point.Point(1, 5)
    point_two = point.Point()
    point_three = point.Point(1, 5)

    print(point_one)
    print(point_two)
    print(point_three)

    print(point_one == point_three)
    print(point_one == point_two)

    print(str(point_one))
    print(len(point_one))

    point_one.translation(10, 10)
    print(point_one)

    print(point_one.distance(point_two))
    print(point_one.distance(point_three))

main()