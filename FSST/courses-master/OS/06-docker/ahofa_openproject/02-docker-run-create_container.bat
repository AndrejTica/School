docker run -d -p 3380:80 --name openproject -e SECRET_KEY_BASE=secret \
  -v /media/home/home/docker/data/openproject/pgdata:/var/lib/postgresql/9.4/main \
  -v /media/home/home/docker/data/openproject/logs:/var/log/supervisor \
  -v /media/home/home/docker/data/openproject/static:/var/db/openproject \
  openproject/community:5.0

