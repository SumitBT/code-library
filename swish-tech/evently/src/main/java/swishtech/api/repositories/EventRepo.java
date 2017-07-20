package swishtech.api.repositories;

import java.util.List;
import org.springframework.data.repository.CrudRepository;
import swishtech.api.models.Event;

public interface EventRepo  extends CrudRepository<Event, Long>
{
	public List<Event> findByAccountId(long accountId);
}