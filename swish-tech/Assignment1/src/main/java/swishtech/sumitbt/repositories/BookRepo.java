package swishtech.sumitbt.repositories;

import org.springframework.data.repository.CrudRepository;
import swishtech.sumitbt.models.Book;

public interface BookRepo extends CrudRepository<Book, Long>
{
	public Book findByBookname(String bookname);
}
