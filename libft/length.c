int length(void **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}
